local util = {}

function util.logf(s, ...)
	io.write(string.format(s, ...), "\n")
end

function util.getOrCreateTable(t, k)
	if not t[k] then
		t[k] = {}
	end
end

function util.count(tbl)
	local count = 0
	for _ in pairs(tbl) do
		count = count + 1
	end
	return count
end


local function compareKeysDefault(left, right)
	return left.key < right.key
end

function util.sortedPairs(tbl, comparator)
	-- warning: this generates a lot of garbage!
	local sorted = {}
	for k, v in pairs(tbl) do
		table.insert(sorted, {key = k, value = v})
	end
	table.sort(sorted, comparator or compareKeysDefault)
	local i = 0
	return function()
		i = i + 1
		if sorted[i] then
			return sorted[i].key, sorted[i].value
		end
		return nil
	end
end

local typeOrder = {
	["ImGui"] = 0,
}
local function compareTypeKeys(left, right)
	local leftOrder = typeOrder[left.key] or math.huge
	local rightOrder = typeOrder[right.key] or math.huge
	if leftOrder ~= rightOrder then
		return leftOrder < rightOrder
	end
	return left.key < right.key
end
function util.elementPairs(imguiFunctions)
	return util.sortedPairs(imguiFunctions, compareTypeKeys)
end

local function compareSourceLocations(left, right)
	if left.value.sourceFilePath ~= right.value.sourceFilePath then
		if left.value.sourceFilePath == nil then return false end
		if right.value.sourceFilePath == nil then return true end
		return left.value.sourceFilePath < right.value.sourceFilePath
	end

	if left.value.sourceFileLine == nil then return false end
	if right.value.sourceFileLine == nil then return true end
	return left.value.sourceFileLine < right.value.sourceFileLine
end
function util.lineNumberPairs(imguiFunctions)
	return util.sortedPairs(imguiFunctions, compareSourceLocations)
end

local function getFile(path)
	local f = io.open(path, 'r')
	local output = assert(f:read("*a"))
	f:close()
	return output
end

local function getGitInfo(fileName)
	local desiredPath, desiredName = fileName:match("(deps/[^/]+)/(.+)")

	-- check to see if the file is in a submodule
	local moduleData = getFile(".gitmodules")
	local submoduleStart, submoduleEnd = moduleData:find("%b[]")
	while submoduleStart do
		local submoduleName = moduleData:sub(submoduleStart, submoduleEnd):match('%b""'):sub(2, -2)
		local submodulePath = moduleData:match("path = (.-)\n")
		local submoduleUrl = moduleData:match("url = (.-)\n")
		local sha1 = getFile(string.format(".git/modules/%s/HEAD", submoduleName)):match("([^\n]+)")
		local repo = submoduleUrl:match("github.com/(.-).git")
		if desiredPath == submodulePath then
			return string.format("https://github.com/%s/blob/%s", repo, sha1), desiredName
		end
		submoduleStart, submoduleEnd = moduleData:find("%b[]", submoduleEnd+1)
	end

	error("file not found in submodule")
end

function util.createGithubLink(path, lineNumber)
	local urlPrefix, filename = getGitInfo(path)
	return string.format("%s/%s#L%d", urlPrefix, filename, lineNumber)
end

return util
