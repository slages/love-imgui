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

function util.sortedPairs(tbl)
	-- warning: this generates a lot of garbage!
	local sorted = {}
	for k, v in pairs(tbl) do
		table.insert(sorted, {key = k, value = v})
	end
	table.sort(sorted, function(left, right) return left.key < right.key end)
	local i = 0
	return function()
		i = i + 1
		if sorted[i] then
			return sorted[i].key, sorted[i].value
		end
		return nil
	end
end

return util
