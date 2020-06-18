local Buffer = {}
local Buffer_mt = {__index = Buffer}
function Buffer.new(indent)
	local obj = setmetatable({indentL=indent, data={}}, Buffer_mt)
	return obj
end

function Buffer:indent(amount)
	self.indentL = self.indentL + (amount or 1)
end

function Buffer:unindent(amount)
	self:indent(amount and -amount or -1)
end

function Buffer:add(s)
	local indent = string.rep("\t", self.indentL)
	table.insert(self.data, indent .. s)
end

function Buffer:addf(f, ...)
	self:add(string.format(f, ...))
end

function Buffer:done()
	return table.concat(self.data, "\n")
end

return Buffer
