foreign class Box {
	foreign construct new(v)
	foreign value
	foreign value=(v)
	set(v) {
		this.value = v
		return this
	}
	get() {
		return this.value
	}
}

foreign class ImVec2 {
	foreign construct new(x, y)
	foreign x
	foreign x=(v)
	foreign y
	foreign y=(v)
	set(newX, newY) {
		x = newX
		y = newY
	}
}

foreign class ImVec4 {
	foreign construct new(x, y, z, w)
	construct new(v) { new(v, v, v, v) }
	construct new(x, y, z) { new(x, y, z, 1) }
	foreign x
	foreign x=(v)
	foreign y
	foreign y=(v)
	foreign z
	foreign z=(v)
	foreign w
	foreign w=(v)
	set(newX, newY, newZ, newW) {
		x = newX
		y = newY
		z = newZ
		w = newW
	}
	set(newX, newY, newZ) {
		set(newX, newY, newX, 1)
	}
	set(v) {
		set(v, v, v, v)
	}
}

class ImGui {
<% for name, data in pairs(imgui.functions.toplevel.validNames) do -%>
<%- helpers.generateWrenSignatures(data) %>
<% end -%>
}
