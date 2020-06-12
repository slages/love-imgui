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

class ImGui {
<% for name, data in pairs(imgui.functions.toplevel.validNames) do -%>
<%- helpers.generateWrenSignatures(data) %>
<% end -%>
}
