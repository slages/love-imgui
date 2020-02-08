Another hacky bindings generator for imgui.

Goals:
- (rough) version independence
- outputs readable/editable C++
- framework-agnostic

Non goals:
- bindings to all struct types
- Bindings to ImDrawList in particular
- configurability (edit the script if you would like something different)
- parser quality :( it's fine ok

TODO:
* manually write bindings for all methods with callbacks
* provide bindings to ImGuiStyle
* provide a userdata type for imguiDrawList? maybe
* resolve the brittleness around overrides issue. Maybe make override names include the argument types ala C++ name mangling?
