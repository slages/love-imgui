<% for elementName, fnElement in util.sortedPairs(imgui.functions) do -%>
# <%- elementName %>

### Supported methods (<%- util.count(fnElement.validNames) %>)
<% for name, data in util.sortedPairs(fnElement.validNames) do -%>
* <%- helpers.generateDocSignature(data) %>
<% end -%>

### Unsupported methods (<%- util.count(fnElement.invalidNames) %>)
<% for name, data in util.sortedPairs(fnElement.invalidNames) do -%>
* ImGui.<%- name %>
<% end -%>
<% end -%>
