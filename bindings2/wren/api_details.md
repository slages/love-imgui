<% for elementName, fnElement in pairs(imgui.functions) do -%>
# <%- elementName %>

### Supported methods (<%- util.count(fnElement.invalidNames) %>)
<% for name, data in pairs(fnElement.validNames) do -%>
* <%- helpers.generateWrenSignatures(data) %>
<% end -%>

### Unsupported methods (<%- util.count(fnElement.invalidNames) %>)
<% for name, data in pairs(fnElement.validNames) do -%>
* <%- name %>
<% end -%>
<% end -%>
