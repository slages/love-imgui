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

return util
