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

return util
