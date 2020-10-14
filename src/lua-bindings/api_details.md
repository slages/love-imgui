This file was automatically generated on Wed Oct 14 05:20:01 2020, UTC
# ImGui

### Supported methods (284)
* [ImGui.CreateContext](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L253)() -> out: ImGuiContext
* [ImGui.DestroyContext](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L254)(ctx: unknown = nil)
 NULL = destroy current context
* [ImGui.GetCurrentContext](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L255)() -> out: ImGuiContext
* [ImGui.SetCurrentContext](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L256)(ctx: unknown)
* [ImGui.GetStyle](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L260)() -> out: ImGuiStyle
 access the Style structure (colors, sizes). Always use PushStyleCol(), PushStyleVar() to modify style mid-frame!
* [ImGui.EndFrame](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L262)()
 ends the Dear ImGui frame. automatically called by Render(). If you don't need to render data (skipping rendering) you may call EndFrame() without Render()... but you'll have wasted CPU already! If you don't need to render, better to not create any windows and not call NewFrame() at all!
* [ImGui.Render](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L263)()
 ends the Dear ImGui frame, finalize the draw data. You can get call GetDrawData() to obtain it and run your rendering function (up to v1.60, this used to call io.RenderDrawListsFn(). Nowadays, we allow and prefer calling your render function yourself.)
* [ImGui.ShowDemoWindow](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L267)(p_open: boolean = nil) -> p_open: boolean
 create Demo window (previously called ShowTestWindow). demonstrate most ImGui features. call this to learn about the library! try to make it always available in your application!
* [ImGui.ShowAboutWindow](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L268)(p_open: boolean = nil) -> p_open: boolean
 create About window. display Dear ImGui version, credits and build/system information.
* [ImGui.ShowMetricsWindow](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L269)(p_open: boolean = nil) -> p_open: boolean
 create Debug/Metrics window. display Dear ImGui internals: draw commands (with individual draw calls and vertices), window list, basic internal state, etc.
* [ImGui.ShowStyleEditor](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L270)(ref: unknown = nil)
 add style editor block (not a window). you can pass in a reference ImGuiStyle structure to compare to, revert to and save to (else it uses the default style)
* [ImGui.ShowStyleSelector](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L271)(label: string) -> out: boolean
 add style selector block (not a window), essentially a combo listing the default styles.
* [ImGui.ShowFontSelector](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L272)(label: string)
 add font selector block (not a window), essentially a combo listing the loaded fonts.
* [ImGui.ShowUserGuide](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L273)()
 add basic help/info block (not a window): how to manipulate ImGui as a end-user (mouse/keyboard controls).
* [ImGui.GetVersion](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L274)() -> out: number
 get the compiled version string e.g. "1.23" (essentially the compiled value for IMGUI_VERSION)
* [ImGui.StyleColorsDark](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L277)(dst: unknown = nil)
 new, recommended style (default)
* [ImGui.StyleColorsClassic](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L278)(dst: unknown = nil)
 classic imgui style
* [ImGui.StyleColorsLight](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L279)(dst: unknown = nil)
 best used with borders and a custom, thicker font
* [ImGui.Begin](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L293)(name: string, p_open: boolean = nil, flags: ImGuiWindowFlags = 0) -> p_open: boolean, out: boolean
* [ImGui.End](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L294)()
* [ImGui.BeginChild](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L302)(id: number, size_x: number = 0, size_y: number = 0, border: boolean = false, flags: ImGuiWindowFlags = 0) -> out: boolean
* [ImGui.EndChild](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L303)()
* [ImGui.IsWindowAppearing](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L307)() -> out: boolean
* [ImGui.IsWindowCollapsed](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L308)() -> out: boolean
* [ImGui.IsWindowFocused](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L309)(flags: ImGuiFocusedFlags = 0) -> out: boolean
 is current window focused? or its root/child, depending on flags. see flags for options.
* [ImGui.IsWindowHovered](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L310)(flags: ImGuiHoveredFlags = 0) -> out: boolean
 is current window hovered (and typically: not blocked by a popup/modal)? see flags for options. NB: If you are trying to check whether your mouse should be dispatched to imgui or to your app, you should use the 'io.WantCaptureMouse' boolean for that! Please read the FAQ!
* [ImGui.GetWindowDrawList](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L311)() -> out: ImDrawList
 get draw list associated to the current window, to append your own drawing primitives
* [ImGui.GetWindowDpiScale](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L312)() -> out: number
 get DPI scale currently associated to the current window's viewport.
* [ImGui.GetWindowPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L314)() -> out_x: number, out_y: number
 get current window position in screen space (useful if you want to do your own drawing via the DrawList API)
* [ImGui.GetWindowSize](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L315)() -> out_x: number, out_y: number
 get current window size
* [ImGui.GetWindowWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L316)() -> out: number
 get current window width (shortcut for GetWindowSize().x)
* [ImGui.GetWindowHeight](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L317)() -> out: number
 get current window height (shortcut for GetWindowSize().y)
* [ImGui.SetNextWindowPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L320)(pos_x: number, pos_y: number, cond: ImGuiCond = 0, pivot_x: number = 0, pivot_y: number = 0)
 set next window position. call before Begin(). use pivot=(0.5f,0.5f) to center on given point, etc.
* [ImGui.SetNextWindowSize](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L321)(size_x: number, size_y: number, cond: ImGuiCond = 0)
 set next window size. set axis to 0.0f to force an auto-fit on this axis. call before Begin()
* [ImGui.SetNextWindowContentSize](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L323)(size_x: number, size_y: number)
 set next window content size (~ scrollable client area, which enforce the range of scrollbars). Not including window decorations (title bar, menu bar, etc.) nor WindowPadding. set an axis to 0.0f to leave it automatic. call before Begin()
* [ImGui.SetNextWindowCollapsed](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L324)(collapsed: boolean, cond: ImGuiCond = 0)
 set next window collapsed state. call before Begin()
* [ImGui.SetNextWindowFocus](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L325)()
 set next window to be focused / top-most. call before Begin()
* [ImGui.SetNextWindowBgAlpha](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L326)(alpha: number)
 set next window background color alpha. helper to easily override the Alpha component of ImGuiCol_WindowBg/ChildBg/PopupBg. you may also use ImGuiWindowFlags_NoBackground.
* [ImGui.SetNextWindowViewport](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L327)(viewport_id: number)
 set next window viewport
* [ImGui.SetWindowFontScale](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L332)(scale: number)
 set font scale. Adjust IO.FontGlobalScale if you want to scale all windows. This is an old API! For correct scaling, prefer to reload font + rebuild ImFontAtlas + call style.ScaleAllSizes().
* [ImGui.SetWindowPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L333)(name: string, pos_x: number, pos_y: number, cond: ImGuiCond = 0)
 set named window position.
* [ImGui.SetWindowSize](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L334)(name: string, size_x: number, size_y: number, cond: ImGuiCond = 0)
 set named window size. set axis to 0.0f to force an auto-fit on this axis.
* [ImGui.SetWindowCollapsed](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L335)(name: string, collapsed: boolean, cond: ImGuiCond = 0)
 set named window collapsed state
* [ImGui.SetWindowFocus](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L336)(name: string)
 set named window to be focused / top-most. use NULL to remove focus.
* [ImGui.GetContentRegionMax](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L340)() -> out_x: number, out_y: number
 current content boundaries (typically window boundaries including scrolling, or current column boundaries), in windows coordinates
* [ImGui.GetContentRegionAvail](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L341)() -> out_x: number, out_y: number
 == GetContentRegionMax() - GetCursorPos()
* [ImGui.GetWindowContentRegionMin](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L342)() -> out_x: number, out_y: number
 content boundaries min (roughly (0,0)-Scroll), in window coordinates
* [ImGui.GetWindowContentRegionMax](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L343)() -> out_x: number, out_y: number
 content boundaries max (roughly (0,0)+Size-Scroll) where Size can be override with SetNextWindowContentSize(), in window coordinates
* [ImGui.GetWindowContentRegionWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L344)() -> out: number
* [ImGui.GetScrollX](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L347)() -> out: number
 get scrolling amount [0..GetScrollMaxX()]
* [ImGui.GetScrollY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L348)() -> out: number
 get scrolling amount [0..GetScrollMaxY()]
* [ImGui.GetScrollMaxX](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L349)() -> out: number
 get maximum scrolling amount ~~ ContentSize.x - WindowSize.x
* [ImGui.GetScrollMaxY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L350)() -> out: number
 get maximum scrolling amount ~~ ContentSize.y - WindowSize.y
* [ImGui.SetScrollX](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L351)(scroll_x: number)
 set scrolling amount [0..GetScrollMaxX()]
* [ImGui.SetScrollY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L352)(scroll_y: number)
 set scrolling amount [0..GetScrollMaxY()]
* [ImGui.SetScrollHereX](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L353)(center_x_ratio: number = 0.5)
 adjust scrolling amount to make current cursor position visible. center_x_ratio=0.0: left, 0.5: center, 1.0: right. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead.
* [ImGui.SetScrollHereY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L354)(center_y_ratio: number = 0.5)
 adjust scrolling amount to make current cursor position visible. center_y_ratio=0.0: top, 0.5: center, 1.0: bottom. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead.
* [ImGui.SetScrollFromPosX](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L355)(local_x: number, center_x_ratio: number = 0.5)
 adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position.
* [ImGui.SetScrollFromPosY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L356)(local_y: number, center_y_ratio: number = 0.5)
 adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position.
* [ImGui.PopFont](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L360)()
* [ImGui.PushStyleColor](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L362)(idx: ImGuiCol, col_x: number, col_y: number, col_z: number, col_w: number)
* [ImGui.PopStyleColor](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L363)(count: number = 1)
* [ImGui.PushStyleVar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L365)(idx: ImGuiStyleVar, val_x: number, val_y: number)
* [ImGui.PopStyleVar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L366)(count: number = 1)
* [ImGui.GetStyleColorVec4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L367)(idx: ImGuiCol) -> out_x: number, out_y: number, out_z: number, out_w: number
 retrieve style color as stored in ImGuiStyle structure. use to feed back into PushStyleColor(), otherwise use GetColorU32() to get style color with style alpha baked in.
* [ImGui.GetFontSize](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L369)() -> out: number
 get current font size (= height in pixels) of current font with current scale applied
* [ImGui.GetFontTexUvWhitePixel](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L370)() -> out_x: number, out_y: number
 get UV coordinate for a while pixel, useful to draw custom shapes via the ImDrawList API
* [ImGui.PushItemWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L376)(item_width: number)
 push width of items for common large "item+label" widgets. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side). 0.0f = default to ~2/3 of windows width,
* [ImGui.PopItemWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L377)()
* [ImGui.SetNextItemWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L378)(item_width: number)
 set width of the _next_ common large "item+label" widget. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side)
* [ImGui.CalcItemWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L379)() -> out: number
 width of item given pushed settings and current cursor position. NOT necessarily the width of last item unlike most 'Item' functions.
* [ImGui.PushTextWrapPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L380)(wrap_local_pos_x: number = 0)
 push word-wrapping position for Text*() commands. < 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space
* [ImGui.PopTextWrapPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L381)()
* [ImGui.PushAllowKeyboardFocus](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L382)(allow_keyboard_focus: boolean)
 allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets
* [ImGui.PopAllowKeyboardFocus](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L383)()
* [ImGui.PushButtonRepeat](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L384)(repeat: boolean)
 in 'repeat' mode, Button*() functions return repeated true in a typematic manner (using io.KeyRepeatDelay/io.KeyRepeatRate setting). Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame.
* [ImGui.PopButtonRepeat](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L385)()
* [ImGui.Separator](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L394)()
 separator, generally horizontal. inside a menu bar or in horizontal layout mode, this becomes a vertical separator.
* [ImGui.SameLine](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L395)(offset_from_start_x: number = 0, spacing: number = -1)
 call between widgets or groups to layout them horizontally. X position given in window coordinates.
* [ImGui.NewLine](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L396)()
 undo a SameLine() or force a new line when in an horizontal-layout context.
* [ImGui.Spacing](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L397)()
 add vertical spacing.
* [ImGui.Dummy](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L398)(size_x: number, size_y: number)
 add a dummy item of given size. unlike InvisibleButton(), Dummy() won't take the mouse click or be navigable into.
* [ImGui.Indent](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L399)(indent_w: number = 0)
 move content position toward the right, by style.IndentSpacing or indent_w if != 0
* [ImGui.Unindent](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L400)(indent_w: number = 0)
 move content position back to the left, by style.IndentSpacing or indent_w if != 0
* [ImGui.BeginGroup](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L401)()
 lock horizontal starting position
* [ImGui.EndGroup](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L402)()
 unlock horizontal starting position + capture the whole group bounding box into one "item" (so you can use IsItemHovered() or layout primitives such as SameLine() on whole group, etc.)
* [ImGui.GetCursorPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L403)() -> out_x: number, out_y: number
 cursor position in window coordinates (relative to window position)
* [ImGui.GetCursorPosX](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L404)() -> out: number
   (some functions are using window-relative coordinates, such as: GetCursorPos, GetCursorStartPos, GetContentRegionMax, GetWindowContentRegion* etc.
* [ImGui.GetCursorPosY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L405)() -> out: number
    other functions such as GetCursorScreenPos or everything in ImDrawList::
* [ImGui.SetCursorPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L406)(local_pos_x: number, local_pos_y: number)
    are using the main, absolute coordinate system.
* [ImGui.SetCursorPosX](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L407)(local_x: number)
    GetWindowPos() + GetCursorPos() == GetCursorScreenPos() etc.)
* [ImGui.SetCursorPosY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L408)(local_y: number)
* [ImGui.GetCursorStartPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L409)() -> out_x: number, out_y: number
 initial cursor position in window coordinates
* [ImGui.GetCursorScreenPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L410)() -> out_x: number, out_y: number
 cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport. Useful to work with ImDrawList API.
* [ImGui.SetCursorScreenPos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L411)(pos_x: number, pos_y: number)
 cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport.
* [ImGui.AlignTextToFramePadding](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L412)()
 vertically align upcoming text baseline to FramePadding.y so that it will align properly to regularly framed items (call if you have text on a line before a framed item)
* [ImGui.GetTextLineHeight](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L413)() -> out: number
 ~ FontSize
* [ImGui.GetTextLineHeightWithSpacing](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L414)() -> out: number
 ~ FontSize + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of text)
* [ImGui.GetFrameHeight](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L415)() -> out: number
 ~ FontSize + style.FramePadding.y * 2
* [ImGui.GetFrameHeightWithSpacing](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L416)() -> out: number
 ~ FontSize + style.FramePadding.y * 2 + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of framed widgets)
* [ImGui.PushID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L428)(int_id: number)
 push integer into the ID stack (will hash integer).
* [ImGui.PopID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L429)()
 pop from the ID stack.
* [ImGui.GetID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L431)(str_id_begin: string, str_id_end: string) -> out: number
* [ImGui.TextUnformatted](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L435)(text: string, text_end: string = nil)
 raw text without formatting. Roughly equivalent to Text("%s", text) but: A) doesn't require null terminated string if 'text_end' is specified, B) it's faster, no memory copy is done, no buffer size limits, recommended for long chunks of text.
* [ImGui.Text](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L436)(fmt: string, ...)
 formatted text
* [ImGui.TextColored](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L438)(col_x: number, col_y: number, col_z: number, col_w: number, fmt: string, ...)
 shortcut for PushStyleColor(ImGuiCol_Text, col); Text(fmt, ...); PopStyleColor();
* [ImGui.TextDisabled](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L440)(fmt: string, ...)
 shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(fmt, ...); PopStyleColor();
* [ImGui.TextWrapped](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L442)(fmt: string, ...)
 shortcut for PushTextWrapPos(0.0f); Text(fmt, ...); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize().
* [ImGui.LabelText](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L444)(label: string, fmt: string, ...)
 display text+label aligned the same way as value+label widgets
* [ImGui.BulletText](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L446)(fmt: string, ...)
 shortcut for Bullet()+Text()
* [ImGui.Button](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L452)(label: string, size_x: number = 0, size_y: number = 0) -> out: boolean
 button
* [ImGui.SmallButton](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L453)(label: string) -> out: boolean
 button with FramePadding=(0,0) to easily embed within text
* [ImGui.InvisibleButton](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L454)(str_id: string, size_x: number, size_y: number, flags: ImGuiButtonFlags = 0) -> out: boolean
 flexible button behavior without the visuals, frequently useful to build custom behaviors using the public api (along with IsItemActive, IsItemHovered, etc.)
* [ImGui.ArrowButton](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L455)(str_id: string, dir: ImGuiDir) -> out: boolean
 square button with an arrow shape
* [ImGui.Image](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L456)(user_texture_id: Image, size_x: number, size_y: number, uv0_x: number = 0, uv0_y: number = 0, uv1_x: number = 1, uv1_y: number = 1, tint_col_x: number = 1, tint_col_y: number = 1, tint_col_z: number = 1, tint_col_w: number = 1, border_col_x: number = 0, border_col_y: number = 0, border_col_z: number = 0, border_col_w: number = 0)
* [ImGui.ImageButton](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L457)(user_texture_id: Image, size_x: number, size_y: number, uv0_x: number = 0, uv0_y: number = 0, uv1_x: number = 1, uv1_y: number = 1, frame_padding: number = -1, bg_col_x: number = 0, bg_col_y: number = 0, bg_col_z: number = 0, bg_col_w: number = 0, tint_col_x: number = 1, tint_col_y: number = 1, tint_col_z: number = 1, tint_col_w: number = 1) -> out: boolean
 <0 frame_padding uses default frame padding settings. 0 for no padding
* [ImGui.Checkbox](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L458)(label: string, v: boolean) -> v: boolean, out: boolean
* [ImGui.CheckboxFlags](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L459)(label: string, flags: number, flags_value: number) -> flags: number, out: boolean
* [ImGui.RadioButton](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L461)(label: string, v: number, v_button: number) -> v: number, out: boolean
 shortcut to handle the above pattern when value is an integer
* [ImGui.ProgressBar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L462)(fraction: number, size_arg_x: number = -1, size_arg_y: number = 0, overlay: string = nil)
* [ImGui.Bullet](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L463)()
 draw a small circle + keep the cursor on the same line. advance cursor x position by GetTreeNodeToLabelSpacing(), same distance that TreeNode() uses
* [ImGui.BeginCombo](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L468)(label: string, preview_value: string, flags: ImGuiComboFlags = 0) -> out: boolean
* [ImGui.EndCombo](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L469)()
 only call EndCombo() if BeginCombo() returns true!
* [ImGui.Combo](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L471)(label: string, current_item: number, items_separated_by_zeros: string, popup_max_height_in_items: number = -1) -> current_item: number, out: boolean
 Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0"
* [ImGui.DragFloat](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L485)(label: string, v: number, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
 If v_min >= v_max we have no bound
* [ImGui.DragFloat2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L486)(label: string, v: table, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* [ImGui.DragFloat3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L487)(label: string, v: table, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* [ImGui.DragFloat4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L488)(label: string, v: table, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* [ImGui.DragFloatRange2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L489)(label: string, v_current_min: number, v_current_max: number, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%.3f", format_max: string = nil, flags: ImGuiSliderFlags = 0) -> v_current_min: number, v_current_max: number, out: boolean
* [ImGui.DragInt](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L490)(label: string, v: number, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
 If v_min >= v_max we have no bound
* [ImGui.DragInt2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L491)(label: string, v: table, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* [ImGui.DragInt3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L492)(label: string, v: table, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* [ImGui.DragInt4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L493)(label: string, v: table, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* [ImGui.DragIntRange2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L494)(label: string, v_current_min: number, v_current_max: number, v_speed: number = 1, v_min: number = 0, v_max: number = 0, format: string = "%d", format_max: string = nil, flags: ImGuiSliderFlags = 0) -> v_current_min: number, v_current_max: number, out: boolean
* [ImGui.SliderFloat](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L504)(label: string, v: number, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
 adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display.
* [ImGui.SliderFloat2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L505)(label: string, v: table, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* [ImGui.SliderFloat3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L506)(label: string, v: table, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* [ImGui.SliderFloat4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L507)(label: string, v: table, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* [ImGui.SliderAngle](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L508)(label: string, v_rad: number, v_degrees_min: number = -360, v_degrees_max: number = 360, format: string = "%.0f deg", flags: ImGuiSliderFlags = 0) -> v_rad: number, out: boolean
* [ImGui.SliderInt](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L509)(label: string, v: number, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* [ImGui.SliderInt2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L510)(label: string, v: table, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* [ImGui.SliderInt3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L511)(label: string, v: table, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* [ImGui.SliderInt4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L512)(label: string, v: table, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* [ImGui.VSliderFloat](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L515)(label: string, size_x: number, size_y: number, v: number, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* [ImGui.VSliderInt](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L516)(label: string, size_x: number, size_y: number, v: number, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* [ImGui.InputFloat](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L525)(label: string, v: number, step: number = 0, step_fast: number = 0, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v: number, out: boolean
* [ImGui.InputFloat2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L526)(label: string, v: table, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* [ImGui.InputFloat3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L527)(label: string, v: table, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* [ImGui.InputFloat4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L528)(label: string, v: table, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* [ImGui.InputInt](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L529)(label: string, v: number, step: number = 1, step_fast: number = 100, flags: ImGuiInputTextFlags = 0) -> v: number, out: boolean
* [ImGui.InputInt2](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L530)(label: string, v: table, flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* [ImGui.InputInt3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L531)(label: string, v: table, flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* [ImGui.InputInt4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L532)(label: string, v: table, flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* [ImGui.InputDouble](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L533)(label: string, v: number, step: number = 0, step_fast: number = 0, format: string = "%.6f", flags: ImGuiInputTextFlags = 0) -> v: number, out: boolean
* [ImGui.ColorEdit3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L540)(label: string, col: table, flags: ImGuiColorEditFlags = 0) -> col[0]: number, col[1]: number, col[2]: number, out: boolean
* [ImGui.ColorEdit4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L541)(label: string, col: table, flags: ImGuiColorEditFlags = 0) -> col[0]: number, col[1]: number, col[2]: number, col[3]: number, out: boolean
* [ImGui.ColorPicker3](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L542)(label: string, col: table, flags: ImGuiColorEditFlags = 0) -> col[0]: number, col[1]: number, col[2]: number, out: boolean
* [ImGui.ColorButton](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L544)(desc_id: string, col_x: number, col_y: number, col_z: number, col_w: number, flags: ImGuiColorEditFlags = 0, size_x: number = 0, size_y: number = 0) -> out: boolean
 display a colored square/button, hover for details, return true when pressed.
* [ImGui.SetColorEditOptions](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L545)(flags: ImGuiColorEditFlags)
 initialize current options (generally on application startup) if you want to select a default format, picker type, etc. User will be able to change many settings, unless you pass the _NoOptions flag to your calls.
* [ImGui.TreeNode](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L550)(str_id: string, fmt: string, ...) -> out: boolean
 helper variation to easily decorelate the id from the displayed string. Read the FAQ about why and how to use ID. to align arbitrary text at the same level as a TreeNode() you can use Bullet().
* [ImGui.TreeNodeEx](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L555)(str_id: string, flags: ImGuiTreeNodeFlags, fmt: string, ...) -> out: boolean
* [ImGui.TreePush](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L559)(str_id: string)
 ~ Indent()+PushId(). Already called by TreeNode() when returning true, but you can call TreePush/TreePop yourself if desired.
* [ImGui.TreePop](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L561)()
 ~ Unindent()+PopId()
* [ImGui.GetTreeNodeToLabelSpacing](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L562)() -> out: number
 horizontal distance preceding label when using TreeNode*() or Bullet() == (g.FontSize + style.FramePadding.x*2) for a regular unframed TreeNode
* [ImGui.CollapsingHeader](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L564)(label: string, p_open: boolean, flags: ImGuiTreeNodeFlags = 0) -> p_open: boolean, out: boolean
 when 'p_open' isn't NULL, display an additional small close button on upper right of the header
* [ImGui.SetNextItemOpen](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L565)(is_open: boolean, cond: ImGuiCond = 0)
 set next TreeNode/CollapsingHeader open state.
* [ImGui.Selectable](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L571)(label: string, p_selected: boolean, flags: ImGuiSelectableFlags = 0, size_x: number = 0, size_y: number = 0) -> p_selected: boolean, out: boolean
 "bool* p_selected" point to the selection state (read-write), as a convenient helper.
* [ImGui.ListBoxHeaderXY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L577)(label: string, size_x: number = 0, size_y: number = 0) -> out: boolean
 use if you want to reimplement ListBox() will custom data or interactions. if the function return true, you can output elements then call ListBoxFooter() afterwards.
* [ImGui.ListBoxHeaderItems](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L578)(label: string, items_count: number, height_in_items: number = -1) -> out: boolean
 "
* [ImGui.ListBoxFooter](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L579)()
 terminate the scrolling region. only call ListBoxFooter() if ListBoxHeader() returned true!
* [ImGui.Value](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L592)(prefix: string, v: number, float_format: string = nil)
* [ImGui.BeginMenuBar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L598)() -> out: boolean
 append to menu-bar of current window (requires ImGuiWindowFlags_MenuBar flag set on parent window).
* [ImGui.EndMenuBar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L599)()
 only call EndMenuBar() if BeginMenuBar() returns true!
* [ImGui.BeginMainMenuBar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L600)() -> out: boolean
 create and append to a full screen menu-bar.
* [ImGui.EndMainMenuBar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L601)()
 only call EndMainMenuBar() if BeginMainMenuBar() returns true!
* [ImGui.BeginMenu](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L602)(label: string, enabled: boolean = true) -> out: boolean
 create a sub-menu entry. only call EndMenu() if this returns true!
* [ImGui.EndMenu](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L603)()
 only call EndMenu() if BeginMenu() returns true!
* [ImGui.MenuItem](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L605)(label: string, shortcut: string, p_selected: boolean, enabled: boolean = true) -> p_selected: boolean, out: boolean
 return true when activated + toggle (*p_selected) if p_selected != NULL
* [ImGui.BeginTooltip](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L609)()
 begin/append a tooltip window. to create full-featured tooltip (with any kind of items).
* [ImGui.EndTooltip](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L610)()
* [ImGui.SetTooltip](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L611)(fmt: string, ...)
 set a text-only tooltip, typically use with ImGui::IsItemHovered(). override any previous call to SetTooltip().
* [ImGui.BeginPopup](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L625)(str_id: string, flags: ImGuiWindowFlags = 0) -> out: boolean
 return true if the popup is open, and you can start outputting to it.
* [ImGui.BeginPopupModal](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L626)(name: string, p_open: boolean = nil, flags: ImGuiWindowFlags = 0) -> p_open: boolean, out: boolean
 return true if the modal is open, and you can start outputting to it.
* [ImGui.EndPopup](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L627)()
 only call EndPopup() if BeginPopupXXX() returns true!
* [ImGui.OpenPopup](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L634)(str_id: string, popup_flags: ImGuiPopupFlags = 0)
 call to mark popup as open (don't call every frame!).
* [ImGui.OpenPopupOnItemClick](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L635)(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1)
 helper to open popup when clicked on last item. return true when just opened. (note: actually triggers on the mouse _released_ event to be consistent with popup behaviors)
* [ImGui.CloseCurrentPopup](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L636)()
 manually close the popup we have begin-ed into.
* [ImGui.BeginPopupContextItem](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L642)(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1) -> out: boolean
 open+begin popup when clicked on last item. if you can pass a NULL str_id only if the previous item had an id. If you want to use that on a non-interactive item such as Text() you need to pass in an explicit ID here. read comments in .cpp!
* [ImGui.BeginPopupContextWindow](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L643)(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1) -> out: boolean
 open+begin popup when clicked on current window.
* [ImGui.BeginPopupContextVoid](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L644)(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1) -> out: boolean
 open+begin popup when clicked in void (where there are no windows).
* [ImGui.IsPopupOpen](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L649)(str_id: string, flags: ImGuiPopupFlags = 0) -> out: boolean
 return true if the popup is open.
* [ImGui.Columns](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L656)(count: number = 1, id: string = nil, border: boolean = true)
* [ImGui.NextColumn](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L657)()
 next column, defaults to current row or next row if the current row is finished
* [ImGui.GetColumnIndex](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L658)() -> out: number
 get current column index
* [ImGui.GetColumnWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L659)(column_index: number = -1) -> out: number
 get column width (in pixels). pass -1 to use current column
* [ImGui.SetColumnWidth](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L660)(column_index: number, width: number)
 set column width (in pixels). pass -1 to use current column
* [ImGui.GetColumnOffset](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L661)(column_index: number = -1) -> out: number
 get position of column line (in pixels, from the left side of the contents region). pass -1 to use current column, otherwise 0..GetColumnsCount() inclusive. column 0 is typically 0.0f
* [ImGui.SetColumnOffset](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L662)(column_index: number, offset_x: number)
 set position of column line (in pixels, from the left side of the contents region). pass -1 to use current column
* [ImGui.GetColumnsCount](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L663)() -> out: number
* [ImGui.BeginTabBar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L667)(str_id: string, flags: ImGuiTabBarFlags = 0) -> out: boolean
 create and append into a TabBar
* [ImGui.EndTabBar](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L668)()
 only call EndTabBar() if BeginTabBar() returns true!
* [ImGui.BeginTabItem](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L669)(label: string, p_open: boolean = nil, flags: ImGuiTabItemFlags = 0) -> p_open: boolean, out: boolean
 create a Tab. Returns true if the Tab is selected.
* [ImGui.EndTabItem](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L670)()
 only call EndTabItem() if BeginTabItem() returns true!
* [ImGui.TabItemButton](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L671)(label: string, flags: ImGuiTabItemFlags = 0) -> out: boolean
 create a Tab behaving like a button. return true when clicked. cannot be selected in the tab bar.
* [ImGui.SetTabItemClosed](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L672)(tab_or_docked_window_label: string)
 notify TabBar or Docking system of a closed tab/window ahead (useful to reduce visual flicker on reorderable tab bars). For tab-bar: call after BeginTabBar() and before Tab submissions. Otherwise call with a window name.
* [ImGui.DockSpace](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L682)(id: number, size_x: number = 0, size_y: number = 0, flags: ImGuiDockNodeFlags = 0)
* [ImGui.DockSpaceOverViewport](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L683)(flags: ImGuiDockNodeFlags = 0) -> out: number
* [ImGui.SetNextWindowDockID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L684)(dock_id: number, cond: ImGuiCond = 0)
 set next window dock id (FIXME-DOCK)
* [ImGui.GetWindowDockID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L686)() -> out: number
* [ImGui.IsWindowDocked](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L687)() -> out: boolean
 is current window docked into another window?
* [ImGui.LogToTTY](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L691)(auto_open_depth: number = -1)
 start logging to tty (stdout)
* [ImGui.LogToFile](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L692)(auto_open_depth: number = -1, filename: string = nil)
 start logging to file
* [ImGui.LogToClipboard](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L693)(auto_open_depth: number = -1)
 start logging to OS clipboard
* [ImGui.LogFinish](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L694)()
 stop logging (close file, etc.)
* [ImGui.LogButtons](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L695)()
 helper to display buttons for logging to tty/file/clipboard
* [ImGui.LogText](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L696)(fmt: string, ...)
 pass text data straight to log (without being displayed)
* [ImGui.BeginDragDropSource](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L701)(flags: ImGuiDragDropFlags = 0) -> out: boolean
 call when the current item is active. If this return true, you can call SetDragDropPayload() + EndDragDropSource()
* [ImGui.EndDragDropSource](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L703)()
 only call EndDragDropSource() if BeginDragDropSource() returns true!
* [ImGui.BeginDragDropTarget](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L704)() -> out: boolean
 call after submitting an item that may receive a payload. If this returns true, you can call AcceptDragDropPayload() + EndDragDropTarget()
* [ImGui.EndDragDropTarget](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L706)()
 only call EndDragDropTarget() if BeginDragDropTarget() returns true!
* [ImGui.PushClipRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L710)(clip_rect_min_x: number, clip_rect_min_y: number, clip_rect_max_x: number, clip_rect_max_y: number, intersect_with_current_clip_rect: boolean)
* [ImGui.PopClipRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L711)()
* [ImGui.SetItemDefaultFocus](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L715)()
 make last item the default focused item of a window.
* [ImGui.SetKeyboardFocusHere](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L716)(offset: number = 0)
 focus keyboard on the next widget. Use positive 'offset' to access sub components of a multiple component widget. Use -1 to access previous widget.
* [ImGui.IsItemHovered](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L721)(flags: ImGuiHoveredFlags = 0) -> out: boolean
 is the last item hovered? (and usable, aka not blocked by a popup, etc.). See ImGuiHoveredFlags for more options.
* [ImGui.IsItemActive](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L722)() -> out: boolean
 is the last item active? (e.g. button being held, text field being edited. This will continuously return true while holding mouse button on an item. Items that don't interact will always return false)
* [ImGui.IsItemFocused](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L723)() -> out: boolean
 is the last item focused for keyboard/gamepad navigation?
* [ImGui.IsItemClicked](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L724)(mouse_button: ImGuiMouseButton = 0) -> out: boolean
 is the last item clicked? (e.g. button/node just clicked on) == IsMouseClicked(mouse_button) && IsItemHovered()
* [ImGui.IsItemVisible](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L725)() -> out: boolean
 is the last item visible? (items may be out of sight because of clipping/scrolling)
* [ImGui.IsItemEdited](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L726)() -> out: boolean
 did the last item modify its underlying value this frame? or was pressed? This is generally the same as the "bool" return value of many widgets.
* [ImGui.IsItemActivated](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L727)() -> out: boolean
 was the last item just made active (item was previously inactive).
* [ImGui.IsItemDeactivated](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L728)() -> out: boolean
 was the last item just made inactive (item was previously active). Useful for Undo/Redo patterns with widgets that requires continuous editing.
* [ImGui.IsItemDeactivatedAfterEdit](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L729)() -> out: boolean
 was the last item just made inactive and made a value change when it was active? (e.g. Slider/Drag moved). Useful for Undo/Redo patterns with widgets that requires continuous editing. Note that you may get false positives (some widgets such as Combo()/ListBox()/Selectable() will return true even when clicking an already selected item).
* [ImGui.IsItemToggledOpen](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L730)() -> out: boolean
 was the last item open state toggled? set by TreeNode().
* [ImGui.IsAnyItemHovered](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L731)() -> out: boolean
 is any item hovered?
* [ImGui.IsAnyItemActive](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L732)() -> out: boolean
 is any item active?
* [ImGui.IsAnyItemFocused](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L733)() -> out: boolean
 is any item focused?
* [ImGui.GetItemRectMin](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L734)() -> out_x: number, out_y: number
 get upper-left bounding rectangle of the last item (screen space)
* [ImGui.GetItemRectMax](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L735)() -> out_x: number, out_y: number
 get lower-right bounding rectangle of the last item (screen space)
* [ImGui.GetItemRectSize](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L736)() -> out_x: number, out_y: number
 get size of last item
* [ImGui.SetItemAllowOverlap](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L737)()
 allow last item to be overlapped by a subsequent item. sometimes useful with invisible buttons, selectables, etc. to catch unused area.
* [ImGui.IsRectVisible](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L741)(rect_min_x: number, rect_min_y: number, rect_max_x: number, rect_max_y: number) -> out: boolean
 test if rectangle (in screen space) is visible / not clipped. to perform coarse clipping on user's side.
* [ImGui.GetTime](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L742)() -> out: number
 get global imgui time. incremented by io.DeltaTime every frame.
* [ImGui.GetFrameCount](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L743)() -> out: number
 get global imgui frame count. incremented by 1 every frame.
* [ImGui.GetBackgroundDrawList](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L744)() -> out: ImDrawList
 get background draw list for the viewport associated to the current window. this draw list will be the first rendering one. Useful to quickly draw shapes/text behind dear imgui contents.
* [ImGui.GetForegroundDrawList](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L745)() -> out: ImDrawList
 get foreground draw list for the viewport associated to the current window. this draw list will be the last rendered one. Useful to quickly draw shapes/text over dear imgui contents.
* [ImGui.GetStyleColorName](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L749)(idx: ImGuiCol) -> out: number
 get a string corresponding to the enum value (for display, saving, etc.).
* [ImGui.CalcListClipping](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L752)(items_count: number, items_height: number, out_items_display_start: number, out_items_display_end: number) -> out_items_display_start: number, out_items_display_end: number
 calculate coarse clipping for large list of evenly sized items. Prefer using the ImGuiListClipper higher-level helper if you can.
* [ImGui.BeginChildFrame](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L753)(id: number, size_x: number, size_y: number, flags: ImGuiWindowFlags = 0) -> out: boolean
 helper to create a child window / scrolling region that looks like a normal widget frame
* [ImGui.EndChildFrame](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L754)()
 always call EndChildFrame() regardless of BeginChildFrame() return values (which indicates a collapsed/clipped window)
* [ImGui.CalcTextSize](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L757)(text: string, text_end: string = nil, hide_text_after_double_hash: boolean = false, wrap_width: number = -1) -> out_x: number, out_y: number
* [ImGui.ColorConvertU32ToFloat4](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L760)(in: number) -> out_x: number, out_y: number, out_z: number, out_w: number
* [ImGui.GetKeyIndex](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L768)(imgui_key: ImGuiKey) -> out: number
 map ImGuiKey_* values into user's key index. == io.KeyMap[key]
* [ImGui.IsKeyDown](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L769)(user_key_index: number) -> out: boolean
 is key being held. == io.KeysDown[user_key_index].
* [ImGui.IsKeyPressed](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L770)(user_key_index: number, repeat: boolean = true) -> out: boolean
 was key pressed (went from !Down to Down)? if repeat=true, uses io.KeyRepeatDelay / KeyRepeatRate
* [ImGui.IsKeyReleased](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L771)(user_key_index: number) -> out: boolean
 was key released (went from Down to !Down)?
* [ImGui.GetKeyPressedAmount](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L772)(key_index: number, repeat_delay: number, rate: number) -> out: number
 uses provided repeat rate/delay. return a count, most often 0 or 1 but might be >1 if RepeatRate is small enough that DeltaTime > RepeatRate
* [ImGui.CaptureKeyboardFromApp](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L773)(want_capture_keyboard_value: boolean = true)
 attention: misleading name! manually override io.WantCaptureKeyboard flag next frame (said flag is entirely left for your application to handle). e.g. force capture keyboard when your widget is being hovered. This is equivalent to setting "io.WantCaptureKeyboard = want_capture_keyboard_value"; after the next NewFrame() call.
* [ImGui.IsMouseDown](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L779)(button: ImGuiMouseButton) -> out: boolean
 is mouse button held?
* [ImGui.IsMouseClicked](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L780)(button: ImGuiMouseButton, repeat: boolean = false) -> out: boolean
 did mouse button clicked? (went from !Down to Down)
* [ImGui.IsMouseReleased](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L781)(button: ImGuiMouseButton) -> out: boolean
 did mouse button released? (went from Down to !Down)
* [ImGui.IsMouseDoubleClicked](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L782)(button: ImGuiMouseButton) -> out: boolean
 did mouse button double-clicked? (note that a double-click will also report IsMouseClicked() == true)
* [ImGui.IsMouseHoveringRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L783)(r_min_x: number, r_min_y: number, r_max_x: number, r_max_y: number, clip: boolean = true) -> out: boolean
 is mouse hovering given bounding rect (in screen space). clipped by current clipping settings, but disregarding of other consideration of focus/window ordering/popup-block.
* [ImGui.IsMousePosValid](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L784)(mouse_pos_x: number = nil, mouse_pos_y: number = nil) -> out: boolean
 by convention we use (-FLT_MAX,-FLT_MAX) to denote that there is no mouse available
* [ImGui.IsAnyMouseDown](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L785)() -> out: boolean
 is any mouse button held?
* [ImGui.GetMousePos](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L786)() -> out_x: number, out_y: number
 shortcut to ImGui::GetIO().MousePos provided by user, to be consistent with other calls
* [ImGui.GetMousePosOnOpeningCurrentPopup](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L787)() -> out_x: number, out_y: number
 retrieve mouse position at the time of opening popup we have BeginPopup() into (helper to avoid user backing that value themselves)
* [ImGui.IsMouseDragging](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L788)(button: ImGuiMouseButton, lock_threshold: number = -1) -> out: boolean
 is mouse dragging? (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold)
* [ImGui.GetMouseDragDelta](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L789)(button: ImGuiMouseButton = 0, lock_threshold: number = -1) -> out_x: number, out_y: number
 return the delta from the initial clicking position while the mouse button is pressed or was just released. This is locked and return 0.0f until the mouse moves past a distance threshold at least once (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold)
* [ImGui.ResetMouseDragDelta](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L790)(button: ImGuiMouseButton = 0)
* [ImGui.GetMouseCursor](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L791)() -> out: string
 get desired cursor type, reset in ImGui::NewFrame(), this is updated during the frame. valid before Render(). If you use software rendering by setting io.MouseDrawCursor ImGui will render those for you
* [ImGui.SetMouseCursor](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L792)(cursor_type: ImGuiMouseCursor)
 set desired cursor type
* [ImGui.CaptureMouseFromApp](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L793)(want_capture_mouse_value: boolean = true)
 attention: misleading name! manually override io.WantCaptureMouse flag next frame (said flag is entirely left for your application to handle). This is equivalent to setting "io.WantCaptureMouse = want_capture_mouse_value;" after the next NewFrame() call.
* [ImGui.GetClipboardText](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L797)() -> out: number
* [ImGui.SetClipboardText](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L798)(text: string)
* [ImGui.LoadIniSettingsFromDisk](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L803)(ini_filename: string)
 call after CreateContext() and before the first call to NewFrame(). NewFrame() automatically calls LoadIniSettingsFromDisk(io.IniFilename).
* [ImGui.SaveIniSettingsToDisk](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L805)(ini_filename: string)
 this is automatically called (if io.IniFilename is not empty) a few seconds after any modification that should be reflected in the .ini file (and also by DestroyContext).
* [ImGui.UpdatePlatformWindows](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L823)()
 call in main loop. will call CreateWindow/ResizeWindow/etc. platform functions for each secondary viewport, and DestroyWindow for each inactive viewport.
* [ImGui.DestroyPlatformWindows](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L825)()
 call DestroyWindow platform functions for all viewports. call from back-end Shutdown() if you need to close platform windows before imgui shutdown. otherwise will be called by DestroyContext().
* [ImGui.InputText](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/misc/cpp/imgui_stdlib.h#L19)(label: string, str: string, flags: ImGuiInputTextFlags = 0, callback: function = nil) -> str: string, out: boolean
* [ImGui.InputTextMultiline](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/misc/cpp/imgui_stdlib.h#L20)(label: string, str: string, size_x: number = 0, size_y: number = 0, flags: ImGuiInputTextFlags = 0, callback: function = nil) -> str: string, out: boolean
* [ImGui.InputTextWithHint](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/misc/cpp/imgui_stdlib.h#L21)(label: string, hint: string, str: string, flags: ImGuiInputTextFlags = 0, callback: function = nil) -> str: string, out: boolean
* ImGui.NewFrame()
* ImGui.ColorPicker4(label, col1, col2, col3, col4, flags)

### Unsupported methods (23)
* [ImGui.AcceptDragDropPayload](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L705)(type: string, flags: ImGuiDragDropFlags = 0)
 accept contents of a given type. If ImGuiDragDropFlags_AcceptBeforeDelivery is set you can peek into the payload before the mouse button is released.
* [ImGui.FindViewportByID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L826)(id: number)
 this is a helper for back-ends.
* ImGui.FindViewportByPlatformHandle(platform_handle)
* [ImGui.GetDragDropPayload](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L707)()
 peek directly into the current payload from anywhere. may return NULL. use ImGuiPayload::IsDataType() to test for the payload type.
* [ImGui.GetDrawData](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L264)()
 valid after Render() and until the next call to NewFrame(). this is what you have to render.
* [ImGui.GetDrawListSharedData](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L748)()
 you may use this when creating your own ImDrawList instances.
* [ImGui.GetFont](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L368)()
 get current font
* [ImGui.GetIO](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L259)()
 access the IO structure (mouse/keyboard/gamepad inputs, time, various configuration options/flags)
* [ImGui.GetMainViewport](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L822)()
 main viewport. same as GetPlatformIO().MainViewport == GetPlatformIO().Viewports[0].
* [ImGui.GetPlatformIO](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L821)()
 platform/renderer functions, for back-end to setup + viewports list.
* [ImGui.GetStateStorage](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L751)()
* [ImGui.GetWindowViewport](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L313)()
 get viewport currently associated to the current window.
* ImGui.ListBox(label, current_item, myfn, data, items_count, height_in_items = -1)
* ImGui.LoadIniSettingsFromMemory(ini_data)
* ImGui.PlotHistogram(label, myfn, data, values_count, values_offset = 0, overlay_text = NULL, scale_min = FLT_MAX, scale_max = FLT_MAX, graph_size = ImVec2(0, 0))
* ImGui.PlotLines(label, myfn, data, values_count, values_offset = 0, overlay_text = NULL, scale_min = FLT_MAX, scale_max = FLT_MAX, graph_size = ImVec2(0, 0))
* ImGui.PushFont(font)
* ImGui.RenderPlatformWindowsDefault(platform_render_arg = NULL, renderer_render_arg = NULL)
* ImGui.SaveIniSettingsToMemory(out_ini_size = NULL)
* ImGui.SetDragDropPayload(type, data, cond = 0)
* ImGui.SetNextWindowClass(window_class)
* ImGui.SetNextWindowSizeConstraints(size_min, size_max, custom_callback = NULL, custom_callback_data = NULL)
* ImGui.SetStateStorage(storage)

# ImDrawList

### Supported methods (37)
* [ImDrawList:PushClipRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2223)(clip_rect_min_x: number, clip_rect_min_y: number, clip_rect_max_x: number, clip_rect_max_y: number, intersect_with_current_clip_rect: boolean = false)
 Render-level scissoring. This is passed down to your render function but not used for CPU-side coarse clipping. Prefer using higher-level ImGui::PushClipRect() to affect logic (hit-testing and widget culling)
* [ImDrawList:PushClipRectFullScreen](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2224)()
* [ImDrawList:PopClipRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2225)()
* [ImDrawList:PushTextureID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2226)(texture_id: Image)
* [ImDrawList:PopTextureID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2227)()
* [ImDrawList:AddLine](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2237)(p1_x: number, p1_y: number, p2_x: number, p2_y: number, col: number, thickness: number = 1)
* [ImDrawList:AddRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2238)(p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, col: number, rounding: number = 0, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All, thickness: number = 1)
 a: upper-left, b: lower-right (== upper-left + size), rounding_corners_flags: 4 bits corresponding to which corner to round
* [ImDrawList:AddRectFilled](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2239)(p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, col: number, rounding: number = 0, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All)
 a: upper-left, b: lower-right (== upper-left + size)
* [ImDrawList:AddRectFilledMultiColor](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2240)(p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, col_upr_left: number, col_upr_right: number, col_bot_right: number, col_bot_left: number)
* [ImDrawList:AddQuad](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2241)(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, col: number, thickness: number = 1)
* [ImDrawList:AddQuadFilled](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2242)(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, col: number)
* [ImDrawList:AddTriangle](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2243)(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, col: number, thickness: number = 1)
* [ImDrawList:AddTriangleFilled](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2244)(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, col: number)
* [ImDrawList:AddCircle](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2245)(center_x: number, center_y: number, radius: number, col: number, num_segments: number = 0, thickness: number = 1)
* [ImDrawList:AddCircleFilled](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2246)(center_x: number, center_y: number, radius: number, col: number, num_segments: number = 0)
* [ImDrawList:AddNgon](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2247)(center_x: number, center_y: number, radius: number, col: number, num_segments: number, thickness: number = 1)
* [ImDrawList:AddNgonFilled](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2248)(center_x: number, center_y: number, radius: number, col: number, num_segments: number)
* [ImDrawList:AddText](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2249)(pos_x: number, pos_y: number, col: number, text_begin: string, text_end: string = nil)
* [ImDrawList:AddBezierCurve](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2253)(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, col: number, thickness: number, num_segments: number = 0)
* [ImDrawList:AddImage](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2259)(user_texture_id: Image, p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, uv_min_x: number = 0, uv_min_y: number = 0, uv_max_x: number = 1, uv_max_y: number = 1, col: number = IM_COL32_WHITE)
* [ImDrawList:AddImageQuad](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2260)(user_texture_id: Image, p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, uv1_x: number = 0, uv1_y: number = 0, uv2_x: number = 1, uv2_y: number = 0, uv3_x: number = 1, uv3_y: number = 1, uv4_x: number = 0, uv4_y: number = 1, col: number = IM_COL32_WHITE)
* [ImDrawList:AddImageRounded](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2261)(user_texture_id: Image, p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, uv_min_x: number, uv_min_y: number, uv_max_x: number, uv_max_y: number, col: number, rounding: number, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All)
* [ImDrawList:PathArcTo](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2269)(center_x: number, center_y: number, radius: number, a_min: number, a_max: number, num_segments: number = 10)
* [ImDrawList:PathArcToFast](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2270)(center_x: number, center_y: number, radius: number, a_min_of_12: number, a_max_of_12: number)
 Use precomputed angles for a 12 steps circle
* [ImDrawList:PathBezierCurveTo](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2271)(p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, num_segments: number = 0)
* [ImDrawList:PathRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2272)(rect_min_x: number, rect_min_y: number, rect_max_x: number, rect_max_y: number, rounding: number = 0, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All)
* [ImDrawList:AddDrawCmd](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2276)()
 This is useful if you need to forcefully create a new draw call (to allow for dependent rendering / blending). Otherwise primitives are merged into the same draw-call as much as possible
* [ImDrawList:CloneOutput](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2277)() -> out: ImDrawList
 Create a clone of the CmdBuffer/IdxBuffer/VtxBuffer.
* [ImDrawList:PrimReserve](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2292)(idx_count: number, vtx_count: number)
* [ImDrawList:PrimUnreserve](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2293)(idx_count: number, vtx_count: number)
* [ImDrawList:PrimRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2294)(a_x: number, a_y: number, b_x: number, b_y: number, col: number)
 Axis aligned rectangle (composed of two triangles)
* [ImDrawList:_ResetForNewFrame](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2302)()
* [ImDrawList:_ClearFreeMemory](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2303)()
* [ImDrawList:_PopUnusedDrawCmd](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2304)()
* [ImDrawList:_OnChangedClipRect](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2305)()
* [ImDrawList:_OnChangedTextureID](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2306)()
* [ImDrawList:_OnChangedVtxOffset](https://github.com/ocornut/imgui/blob/682249396f02b8c21e5ff333ab4a1969c89387ad/imgui.h#L2307)()

### Unsupported methods (3)
* ImGui.AddCallback(callback, callback_data)
* ImGui.AddConvexPolyFilled(points, num_points, col)
* ImGui.AddPolyline(points, num_points, col, closed, thickness)

