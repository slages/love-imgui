This file was automatically generated on <%- os.date("!%c") %>, UTC
<% for elementName, fnElement in util.elementPairs(imgui.functions) do -%>
# <%- elementName %>

### Supported methods (<%- util.count(fnElement.validNames) %>)
<% for name, data in util.lineNumberPairs(fnElement.validNames) do -%>
* <%- helpers.generateDocSignature(data) %>
<% end -%>

### Unsupported methods (<%- util.count(fnElement.invalidNames) %>)
<% for name, data in util.sortedPairs(fnElement.invalidNames) do -%>
* <%- helpers.generateDocSignature(data) %>
<% end -%>

<% end -%>
