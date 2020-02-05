Another hacky bindings generator for imgui.

Goals:
- (rough) version independence
- outputs readable/editable C++
- framework-agnostic

Non goals:
- bindings to all struct types
- Bindings to ImDrawList in particular
- configurability (edit the script if you would like something different)
- parser quality :( it's fine tho

TODO:
* provide user-configurable bindings for ImTextureID
* manually write bindings for all methods with callbacks
* manually write bindings for all methods that have type signature overrides
* manually write bindings for all varargs methods (do the string formatting in lua, then just give me a monolithic string)
* provide bindings to switch around contexts (shared ptr)
