local util = {}

function util.logf(s, ...)
	io.write(string.format(s, ...), "\n")
end

function util.getOrCreateTable(t, k)
	if not t[k] then
		t[k] = {}
	end
end

return util
