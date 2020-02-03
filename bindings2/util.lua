local util = {}

function util.logf(s, ...)
	io.write(string.format(s, ...), "\n")
end

return util
