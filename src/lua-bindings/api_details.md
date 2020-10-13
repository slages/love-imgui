This file was automatically generated on Tue Oct 13 04:44:48 2020, UTC
# ImGui

### Supported methods (284)
* ImGui.AlignTextToFramePadding()
* ImGui.ArrowButton(str_id: string, dir: ImGuiDir) -> out: boolean
* ImGui.Begin(name: string, p_open: boolean = nil, flags: ImGuiWindowFlags = 0) -> p_open: boolean, out: boolean
* ImGui.BeginChild(id: number, size_x: number = 0, size_y: number =  0, border: boolean = false, flags: ImGuiWindowFlags = 0) -> out: boolean
* ImGui.BeginChildFrame(id: number, size_x: number, size_y: number, flags: ImGuiWindowFlags = 0) -> out: boolean
* ImGui.BeginCombo(label: string, preview_value: string, flags: ImGuiComboFlags = 0) -> out: boolean
* ImGui.BeginDragDropSource(flags: ImGuiDragDropFlags = 0) -> out: boolean
* ImGui.BeginDragDropTarget() -> out: boolean
* ImGui.BeginGroup()
* ImGui.BeginMainMenuBar() -> out: boolean
* ImGui.BeginMenu(label: string, enabled: boolean = true) -> out: boolean
* ImGui.BeginMenuBar() -> out: boolean
* ImGui.BeginPopup(str_id: string, flags: ImGuiWindowFlags = 0) -> out: boolean
* ImGui.BeginPopupContextItem(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1) -> out: boolean
* ImGui.BeginPopupContextVoid(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1) -> out: boolean
* ImGui.BeginPopupContextWindow(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1) -> out: boolean
* ImGui.BeginPopupModal(name: string, p_open: boolean = nil, flags: ImGuiWindowFlags = 0) -> p_open: boolean, out: boolean
* ImGui.BeginTabBar(str_id: string, flags: ImGuiTabBarFlags = 0) -> out: boolean
* ImGui.BeginTabItem(label: string, p_open: boolean = nil, flags: ImGuiTabItemFlags = 0) -> p_open: boolean, out: boolean
* ImGui.BeginTooltip()
* ImGui.Bullet()
* ImGui.BulletText(fmt: string, ...)
* ImGui.Button(label: string, size_x: number = 0, size_y: number =  0) -> out: boolean
* ImGui.CalcItemWidth() -> out: number
* ImGui.CalcListClipping(items_count: number, items_height: number, out_items_display_start: number, out_items_display_end: number) -> out_items_display_start: number, out_items_display_end: number
* ImGui.CalcTextSize(text: string, text_end: string = nil, hide_text_after_double_hash: boolean = false, wrap_width: number = -1.0) -> out_x: number, out_y: number
* ImGui.CaptureKeyboardFromApp(want_capture_keyboard_value: boolean = true)
* ImGui.CaptureMouseFromApp(want_capture_mouse_value: boolean = true)
* ImGui.Checkbox(label: string, v: boolean) -> v: boolean, out: boolean
* ImGui.CheckboxFlags(label: string, flags: number, flags_value: number) -> flags: number, out: boolean
* ImGui.CloseCurrentPopup()
* ImGui.CollapsingHeader(label: string, p_open: boolean, flags: ImGuiTreeNodeFlags = 0) -> p_open: boolean, out: boolean
* ImGui.ColorButton(desc_id: string, col_x: number, col_y: number, col_z: number, col_w: number, flags: ImGuiColorEditFlags = 0, size_x: number = 0, size_y: number =  0) -> out: boolean
* ImGui.ColorConvertU32ToFloat4(in: number) -> out_x: number, out_y: number, out_z: number, out_w: number
* ImGui.ColorEdit3(label: string, col: table, flags: ImGuiColorEditFlags = 0) -> col[0]: number, col[1]: number, col[2]: number, out: boolean
* ImGui.ColorEdit4(label: string, col: table, flags: ImGuiColorEditFlags = 0) -> col[0]: number, col[1]: number, col[2]: number, col[3]: number, out: boolean
* ImGui.ColorPicker3(label: string, col: table, flags: ImGuiColorEditFlags = 0) -> col[0]: number, col[1]: number, col[2]: number, out: boolean
* ImGui.ColorPicker4(label, col1, col2, col3, col4, flags)
* ImGui.Columns(count: number = 1, id: string = nil, border: boolean = true)
* ImGui.Combo(label: string, current_item: number, items_separated_by_zeros: string, popup_max_height_in_items: number = -1) -> current_item: number, out: boolean
* ImGui.CreateContext() -> out: ImGuiContext
* ImGui.DestroyContext(ctx: unknown = nil)
* ImGui.DestroyPlatformWindows()
* ImGui.DockSpace(id: number, size_x: number = 0, size_y: number =  0, flags: ImGuiDockNodeFlags = 0)
* ImGui.DockSpaceOverViewport(flags: ImGuiDockNodeFlags = 0) -> out: number
* ImGui.DragFloat(label: string, v: number, v_speed: number = 1.0, v_min: number = 0.0, v_max: number = 0.0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* ImGui.DragFloat2(label: string, v: table, v_speed: number = 1.0, v_min: number = 0.0, v_max: number = 0.0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* ImGui.DragFloat3(label: string, v: table, v_speed: number = 1.0, v_min: number = 0.0, v_max: number = 0.0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* ImGui.DragFloat4(label: string, v: table, v_speed: number = 1.0, v_min: number = 0.0, v_max: number = 0.0, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* ImGui.DragFloatRange2(label: string, v_current_min: number, v_current_max: number, v_speed: number = 1.0, v_min: number = 0.0, v_max: number = 0.0, format: string = "%.3f", format_max: string = nil, flags: ImGuiSliderFlags = 0) -> v_current_min: number, v_current_max: number, out: boolean
* ImGui.DragInt(label: string, v: number, v_speed: number = 1.0, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* ImGui.DragInt2(label: string, v: table, v_speed: number = 1.0, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* ImGui.DragInt3(label: string, v: table, v_speed: number = 1.0, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* ImGui.DragInt4(label: string, v: table, v_speed: number = 1.0, v_min: number = 0, v_max: number = 0, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* ImGui.DragIntRange2(label: string, v_current_min: number, v_current_max: number, v_speed: number = 1.0, v_min: number = 0, v_max: number = 0, format: string = "%d", format_max: string = nil, flags: ImGuiSliderFlags = 0) -> v_current_min: number, v_current_max: number, out: boolean
* ImGui.Dummy(size_x: number, size_y: number)
* ImGui.End()
* ImGui.EndChild()
* ImGui.EndChildFrame()
* ImGui.EndCombo()
* ImGui.EndDragDropSource()
* ImGui.EndDragDropTarget()
* ImGui.EndFrame()
* ImGui.EndGroup()
* ImGui.EndMainMenuBar()
* ImGui.EndMenu()
* ImGui.EndMenuBar()
* ImGui.EndPopup()
* ImGui.EndTabBar()
* ImGui.EndTabItem()
* ImGui.EndTooltip()
* ImGui.GetBackgroundDrawList() -> out: ImDrawList
* ImGui.GetClipboardText() -> out: number
* ImGui.GetColumnIndex() -> out: number
* ImGui.GetColumnOffset(column_index: number = -1) -> out: number
* ImGui.GetColumnWidth(column_index: number = -1) -> out: number
* ImGui.GetColumnsCount() -> out: number
* ImGui.GetContentRegionAvail() -> out_x: number, out_y: number
* ImGui.GetContentRegionMax() -> out_x: number, out_y: number
* ImGui.GetCurrentContext() -> out: ImGuiContext
* ImGui.GetCursorPos() -> out_x: number, out_y: number
* ImGui.GetCursorPosX() -> out: number
* ImGui.GetCursorPosY() -> out: number
* ImGui.GetCursorScreenPos() -> out_x: number, out_y: number
* ImGui.GetCursorStartPos() -> out_x: number, out_y: number
* ImGui.GetFontSize() -> out: number
* ImGui.GetFontTexUvWhitePixel() -> out_x: number, out_y: number
* ImGui.GetForegroundDrawList() -> out: ImDrawList
* ImGui.GetFrameCount() -> out: number
* ImGui.GetFrameHeight() -> out: number
* ImGui.GetFrameHeightWithSpacing() -> out: number
* ImGui.GetID(str_id_begin: string, str_id_end: string) -> out: number
* ImGui.GetItemRectMax() -> out_x: number, out_y: number
* ImGui.GetItemRectMin() -> out_x: number, out_y: number
* ImGui.GetItemRectSize() -> out_x: number, out_y: number
* ImGui.GetKeyIndex(imgui_key: ImGuiKey) -> out: number
* ImGui.GetKeyPressedAmount(key_index: number, repeat_delay: number, rate: number) -> out: number
* ImGui.GetMouseCursor() -> out: string
* ImGui.GetMouseDragDelta(button: ImGuiMouseButton = 0, lock_threshold: number = -1.0) -> out_x: number, out_y: number
* ImGui.GetMousePos() -> out_x: number, out_y: number
* ImGui.GetMousePosOnOpeningCurrentPopup() -> out_x: number, out_y: number
* ImGui.GetScrollMaxX() -> out: number
* ImGui.GetScrollMaxY() -> out: number
* ImGui.GetScrollX() -> out: number
* ImGui.GetScrollY() -> out: number
* ImGui.GetStyle() -> out: ImGuiStyle
* ImGui.GetStyleColorName(idx: ImGuiCol) -> out: number
* ImGui.GetStyleColorVec4(idx: ImGuiCol) -> out_x: number, out_y: number, out_z: number, out_w: number
* ImGui.GetTextLineHeight() -> out: number
* ImGui.GetTextLineHeightWithSpacing() -> out: number
* ImGui.GetTime() -> out: number
* ImGui.GetTreeNodeToLabelSpacing() -> out: number
* ImGui.GetVersion() -> out: number
* ImGui.GetWindowContentRegionMax() -> out_x: number, out_y: number
* ImGui.GetWindowContentRegionMin() -> out_x: number, out_y: number
* ImGui.GetWindowContentRegionWidth() -> out: number
* ImGui.GetWindowDockID() -> out: number
* ImGui.GetWindowDpiScale() -> out: number
* ImGui.GetWindowDrawList() -> out: ImDrawList
* ImGui.GetWindowHeight() -> out: number
* ImGui.GetWindowPos() -> out_x: number, out_y: number
* ImGui.GetWindowSize() -> out_x: number, out_y: number
* ImGui.GetWindowWidth() -> out: number
* ImGui.Image(user_texture_id: Image, size_x: number, size_y: number, uv0_x: number = 0, uv0_y: number =  0, uv1_x: number = 1, uv1_y: number = 1, tint_col_x: number = 1, tint_col_y: number = 1, tint_col_z: number = 1, tint_col_w: number = 1, border_col_x: number = 0, border_col_y: number = 0, border_col_z: number = 0, border_col_w: number = 0)
* ImGui.ImageButton(user_texture_id: Image, size_x: number, size_y: number, uv0_x: number = 0, uv0_y: number =  0, uv1_x: number = 1, uv1_y: number = 1, frame_padding: number = -1, bg_col_x: number = 0, bg_col_y: number = 0, bg_col_z: number = 0, bg_col_w: number = 0, tint_col_x: number = 1, tint_col_y: number = 1, tint_col_z: number = 1, tint_col_w: number = 1) -> out: boolean
* ImGui.Indent(indent_w: number = 0.0)
* ImGui.InputDouble(label: string, v: number, step: number = 0.0, step_fast: number = 0.0, format: string = "%.6f", flags: ImGuiInputTextFlags = 0) -> v: number, out: boolean
* ImGui.InputFloat(label: string, v: number, step: number = 0.0, step_fast: number = 0.0, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v: number, out: boolean
* ImGui.InputFloat2(label: string, v: table, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* ImGui.InputFloat3(label: string, v: table, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* ImGui.InputFloat4(label: string, v: table, format: string = "%.3f", flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* ImGui.InputInt(label: string, v: number, step: number = 1, step_fast: number = 100, flags: ImGuiInputTextFlags = 0) -> v: number, out: boolean
* ImGui.InputInt2(label: string, v: table, flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* ImGui.InputInt3(label: string, v: table, flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* ImGui.InputInt4(label: string, v: table, flags: ImGuiInputTextFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* ImGui.InputText(label: string, str: string, flags: ImGuiInputTextFlags = 0, callback: function) -> str: string, out: boolean
* ImGui.InputTextMultiline(label: string, str: string, size_x: number = 0, size_y: number =  0, flags: ImGuiInputTextFlags = 0, callback: function) -> str: string, out: boolean
* ImGui.InputTextWithHint(label: string, hint: string, str: string, flags: ImGuiInputTextFlags = 0, callback: function) -> str: string, out: boolean
* ImGui.InvisibleButton(str_id: string, size_x: number, size_y: number, flags: ImGuiButtonFlags = 0) -> out: boolean
* ImGui.IsAnyItemActive() -> out: boolean
* ImGui.IsAnyItemFocused() -> out: boolean
* ImGui.IsAnyItemHovered() -> out: boolean
* ImGui.IsAnyMouseDown() -> out: boolean
* ImGui.IsItemActivated() -> out: boolean
* ImGui.IsItemActive() -> out: boolean
* ImGui.IsItemClicked(mouse_button: ImGuiMouseButton = 0) -> out: boolean
* ImGui.IsItemDeactivated() -> out: boolean
* ImGui.IsItemDeactivatedAfterEdit() -> out: boolean
* ImGui.IsItemEdited() -> out: boolean
* ImGui.IsItemFocused() -> out: boolean
* ImGui.IsItemHovered(flags: ImGuiHoveredFlags = 0) -> out: boolean
* ImGui.IsItemToggledOpen() -> out: boolean
* ImGui.IsItemVisible() -> out: boolean
* ImGui.IsKeyDown(user_key_index: number) -> out: boolean
* ImGui.IsKeyPressed(user_key_index: number, repeat: boolean = true) -> out: boolean
* ImGui.IsKeyReleased(user_key_index: number) -> out: boolean
* ImGui.IsMouseClicked(button: ImGuiMouseButton, repeat: boolean = false) -> out: boolean
* ImGui.IsMouseDoubleClicked(button: ImGuiMouseButton) -> out: boolean
* ImGui.IsMouseDown(button: ImGuiMouseButton) -> out: boolean
* ImGui.IsMouseDragging(button: ImGuiMouseButton, lock_threshold: number = -1.0) -> out: boolean
* ImGui.IsMouseHoveringRect(r_min_x: number, r_min_y: number, r_max_x: number, r_max_y: number, clip: boolean = true) -> out: boolean
* ImGui.IsMousePosValid(mouse_pos_x: number = nil, mouse_pos_y: number = nil) -> out: boolean
* ImGui.IsMouseReleased(button: ImGuiMouseButton) -> out: boolean
* ImGui.IsPopupOpen(str_id: string, flags: ImGuiPopupFlags = 0) -> out: boolean
* ImGui.IsRectVisible(rect_min_x: number, rect_min_y: number, rect_max_x: number, rect_max_y: number) -> out: boolean
* ImGui.IsWindowAppearing() -> out: boolean
* ImGui.IsWindowCollapsed() -> out: boolean
* ImGui.IsWindowDocked() -> out: boolean
* ImGui.IsWindowFocused(flags: ImGuiFocusedFlags = 0) -> out: boolean
* ImGui.IsWindowHovered(flags: ImGuiHoveredFlags = 0) -> out: boolean
* ImGui.LabelText(label: string, fmt: string, ...)
* ImGui.ListBoxFooter()
* ImGui.ListBoxHeaderItems(label: string, items_count: number, height_in_items: number = -1) -> out: boolean
* ImGui.ListBoxHeaderXY(label: string, size_x: number = 0, size_y: number =  0) -> out: boolean
* ImGui.LoadIniSettingsFromDisk(ini_filename: string)
* ImGui.LogButtons()
* ImGui.LogFinish()
* ImGui.LogText(fmt: string, ...)
* ImGui.LogToClipboard(auto_open_depth: number = -1)
* ImGui.LogToFile(auto_open_depth: number = -1, filename: string = nil)
* ImGui.LogToTTY(auto_open_depth: number = -1)
* ImGui.MenuItem(label: string, shortcut: string, p_selected: boolean, enabled: boolean = true) -> p_selected: boolean, out: boolean
* ImGui.NewFrame()
* ImGui.NewLine()
* ImGui.NextColumn()
* ImGui.OpenPopup(str_id: string, popup_flags: ImGuiPopupFlags = 0)
* ImGui.OpenPopupOnItemClick(str_id: string = nil, popup_flags: ImGuiPopupFlags = 1)
* ImGui.PopAllowKeyboardFocus()
* ImGui.PopButtonRepeat()
* ImGui.PopClipRect()
* ImGui.PopFont()
* ImGui.PopID()
* ImGui.PopItemWidth()
* ImGui.PopStyleColor(count: number = 1)
* ImGui.PopStyleVar(count: number = 1)
* ImGui.PopTextWrapPos()
* ImGui.ProgressBar(fraction: number, size_arg_x: number = -1, size_arg_y: number =  0, overlay: string = nil)
* ImGui.PushAllowKeyboardFocus(allow_keyboard_focus: boolean)
* ImGui.PushButtonRepeat(repeat: boolean)
* ImGui.PushClipRect(clip_rect_min_x: number, clip_rect_min_y: number, clip_rect_max_x: number, clip_rect_max_y: number, intersect_with_current_clip_rect: boolean)
* ImGui.PushID(int_id: number)
* ImGui.PushItemWidth(item_width: number)
* ImGui.PushStyleColor(idx: ImGuiCol, col_x: number, col_y: number, col_z: number, col_w: number)
* ImGui.PushStyleVar(idx: ImGuiStyleVar, val_x: number, val_y: number)
* ImGui.PushTextWrapPos(wrap_local_pos_x: number = 0.0)
* ImGui.RadioButton(label: string, v: number, v_button: number) -> v: number, out: boolean
* ImGui.Render()
* ImGui.ResetMouseDragDelta(button: ImGuiMouseButton = 0)
* ImGui.SameLine(offset_from_start_x: number = 0.0, spacing: number = -1.0)
* ImGui.SaveIniSettingsToDisk(ini_filename: string)
* ImGui.Selectable(label: string, p_selected: boolean, flags: ImGuiSelectableFlags = 0, size_x: number = 0, size_y: number =  0) -> p_selected: boolean, out: boolean
* ImGui.Separator()
* ImGui.SetClipboardText(text: string)
* ImGui.SetColorEditOptions(flags: ImGuiColorEditFlags)
* ImGui.SetColumnOffset(column_index: number, offset_x: number)
* ImGui.SetColumnWidth(column_index: number, width: number)
* ImGui.SetCurrentContext(ctx: unknown)
* ImGui.SetCursorPos(local_pos_x: number, local_pos_y: number)
* ImGui.SetCursorPosX(local_x: number)
* ImGui.SetCursorPosY(local_y: number)
* ImGui.SetCursorScreenPos(pos_x: number, pos_y: number)
* ImGui.SetItemAllowOverlap()
* ImGui.SetItemDefaultFocus()
* ImGui.SetKeyboardFocusHere(offset: number = 0)
* ImGui.SetMouseCursor(cursor_type: ImGuiMouseCursor)
* ImGui.SetNextItemOpen(is_open: boolean, cond: ImGuiCond = 0)
* ImGui.SetNextItemWidth(item_width: number)
* ImGui.SetNextWindowBgAlpha(alpha: number)
* ImGui.SetNextWindowCollapsed(collapsed: boolean, cond: ImGuiCond = 0)
* ImGui.SetNextWindowContentSize(size_x: number, size_y: number)
* ImGui.SetNextWindowDockID(dock_id: number, cond: ImGuiCond = 0)
* ImGui.SetNextWindowFocus()
* ImGui.SetNextWindowPos(pos_x: number, pos_y: number, cond: ImGuiCond = 0, pivot_x: number = 0, pivot_y: number =  0)
* ImGui.SetNextWindowSize(size_x: number, size_y: number, cond: ImGuiCond = 0)
* ImGui.SetNextWindowViewport(viewport_id: number)
* ImGui.SetScrollFromPosX(local_x: number, center_x_ratio: number = 0.5)
* ImGui.SetScrollFromPosY(local_y: number, center_y_ratio: number = 0.5)
* ImGui.SetScrollHereX(center_x_ratio: number = 0.5)
* ImGui.SetScrollHereY(center_y_ratio: number = 0.5)
* ImGui.SetScrollX(scroll_x: number)
* ImGui.SetScrollY(scroll_y: number)
* ImGui.SetTabItemClosed(tab_or_docked_window_label: string)
* ImGui.SetTooltip(fmt: string, ...)
* ImGui.SetWindowCollapsed(name: string, collapsed: boolean, cond: ImGuiCond = 0)
* ImGui.SetWindowFocus(name: string)
* ImGui.SetWindowFontScale(scale: number)
* ImGui.SetWindowPos(name: string, pos_x: number, pos_y: number, cond: ImGuiCond = 0)
* ImGui.SetWindowSize(name: string, size_x: number, size_y: number, cond: ImGuiCond = 0)
* ImGui.ShowAboutWindow(p_open: boolean = nil) -> p_open: boolean
* ImGui.ShowDemoWindow(p_open: boolean = nil) -> p_open: boolean
* ImGui.ShowFontSelector(label: string)
* ImGui.ShowMetricsWindow(p_open: boolean = nil) -> p_open: boolean
* ImGui.ShowStyleEditor(ref: unknown = nil)
* ImGui.ShowStyleSelector(label: string) -> out: boolean
* ImGui.ShowUserGuide()
* ImGui.SliderAngle(label: string, v_rad: number, v_degrees_min: number = -360.0, v_degrees_max: number = +360.0, format: string = "%.0f deg", flags: ImGuiSliderFlags = 0) -> v_rad: number, out: boolean
* ImGui.SliderFloat(label: string, v: number, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* ImGui.SliderFloat2(label: string, v: table, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* ImGui.SliderFloat3(label: string, v: table, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* ImGui.SliderFloat4(label: string, v: table, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* ImGui.SliderInt(label: string, v: number, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* ImGui.SliderInt2(label: string, v: table, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, out: boolean
* ImGui.SliderInt3(label: string, v: table, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, out: boolean
* ImGui.SliderInt4(label: string, v: table, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v[0]: number, v[1]: number, v[2]: number, v[3]: number, out: boolean
* ImGui.SmallButton(label: string) -> out: boolean
* ImGui.Spacing()
* ImGui.StyleColorsClassic(dst: unknown = nil)
* ImGui.StyleColorsDark(dst: unknown = nil)
* ImGui.StyleColorsLight(dst: unknown = nil)
* ImGui.TabItemButton(label: string, flags: ImGuiTabItemFlags = 0) -> out: boolean
* ImGui.Text(fmt: string, ...)
* ImGui.TextColored(col_x: number, col_y: number, col_z: number, col_w: number, fmt: string, ...)
* ImGui.TextDisabled(fmt: string, ...)
* ImGui.TextUnformatted(text: string, text_end: string = nil)
* ImGui.TextWrapped(fmt: string, ...)
* ImGui.TreeNode(str_id: string, fmt: string, ...) -> out: boolean
* ImGui.TreeNodeEx(str_id: string, flags: ImGuiTreeNodeFlags, fmt: string, ...) -> out: boolean
* ImGui.TreePop()
* ImGui.TreePush(str_id: string)
* ImGui.Unindent(indent_w: number = 0.0)
* ImGui.UpdatePlatformWindows()
* ImGui.VSliderFloat(label: string, size_x: number, size_y: number, v: number, v_min: number, v_max: number, format: string = "%.3f", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* ImGui.VSliderInt(label: string, size_x: number, size_y: number, v: number, v_min: number, v_max: number, format: string = "%d", flags: ImGuiSliderFlags = 0) -> v: number, out: boolean
* ImGui.Value(prefix: string, v: number, float_format: string = nil)

### Unsupported methods (23)
* ImGui.AcceptDragDropPayload(type: string, flags: ImGuiDragDropFlags = 0)
* ImGui.FindViewportByID(id: number)
* ImGui.FindViewportByPlatformHandle(platform_handle)
* ImGui.GetDragDropPayload()
* ImGui.GetDrawData()
* ImGui.GetDrawListSharedData()
* ImGui.GetFont()
* ImGui.GetIO()
* ImGui.GetMainViewport()
* ImGui.GetPlatformIO()
* ImGui.GetStateStorage()
* ImGui.GetWindowViewport()
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
* ImDrawList:AddBezierCurve(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, col: number, thickness: number, num_segments: number = 0)
* ImDrawList:AddCircle(center_x: number, center_y: number, radius: number, col: number, num_segments: number = 0, thickness: number = 1.0)
* ImDrawList:AddCircleFilled(center_x: number, center_y: number, radius: number, col: number, num_segments: number = 0)
* ImDrawList:AddDrawCmd()
* ImDrawList:AddImage(user_texture_id: Image, p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, uv_min_x: number = 0, uv_min_y: number =  0, uv_max_x: number = 1, uv_max_y: number =  1, col: number = IM_COL32_WHITE)
* ImDrawList:AddImageQuad(user_texture_id: Image, p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, uv1_x: number = 0, uv1_y: number =  0, uv2_x: number = 1, uv2_y: number =  0, uv3_x: number = 1, uv3_y: number =  1, uv4_x: number = 0, uv4_y: number =  1, col: number = IM_COL32_WHITE)
* ImDrawList:AddImageRounded(user_texture_id: Image, p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, uv_min_x: number, uv_min_y: number, uv_max_x: number, uv_max_y: number, col: number, rounding: number, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All)
* ImDrawList:AddLine(p1_x: number, p1_y: number, p2_x: number, p2_y: number, col: number, thickness: number = 1.0)
* ImDrawList:AddNgon(center_x: number, center_y: number, radius: number, col: number, num_segments: number, thickness: number = 1.0)
* ImDrawList:AddNgonFilled(center_x: number, center_y: number, radius: number, col: number, num_segments: number)
* ImDrawList:AddQuad(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, col: number, thickness: number = 1.0)
* ImDrawList:AddQuadFilled(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, col: number)
* ImDrawList:AddRect(p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, col: number, rounding: number = 0.0, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All, thickness: number = 1.0)
* ImDrawList:AddRectFilled(p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, col: number, rounding: number = 0.0, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All)
* ImDrawList:AddRectFilledMultiColor(p_min_x: number, p_min_y: number, p_max_x: number, p_max_y: number, col_upr_left: number, col_upr_right: number, col_bot_right: number, col_bot_left: number)
* ImDrawList:AddText(pos_x: number, pos_y: number, col: number, text_begin: string, text_end: string = nil)
* ImDrawList:AddTriangle(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, col: number, thickness: number = 1.0)
* ImDrawList:AddTriangleFilled(p1_x: number, p1_y: number, p2_x: number, p2_y: number, p3_x: number, p3_y: number, col: number)
* ImDrawList:CloneOutput() -> out: ImDrawList
* ImDrawList:PathArcTo(center_x: number, center_y: number, radius: number, a_min: number, a_max: number, num_segments: number = 10)
* ImDrawList:PathArcToFast(center_x: number, center_y: number, radius: number, a_min_of_12: number, a_max_of_12: number)
* ImDrawList:PathBezierCurveTo(p2_x: number, p2_y: number, p3_x: number, p3_y: number, p4_x: number, p4_y: number, num_segments: number = 0)
* ImDrawList:PathRect(rect_min_x: number, rect_min_y: number, rect_max_x: number, rect_max_y: number, rounding: number = 0.0, rounding_corners: ImDrawCornerFlags = ImDrawCornerFlags_All)
* ImDrawList:PopClipRect()
* ImDrawList:PopTextureID()
* ImDrawList:PrimRect(a_x: number, a_y: number, b_x: number, b_y: number, col: number)
* ImDrawList:PrimReserve(idx_count: number, vtx_count: number)
* ImDrawList:PrimUnreserve(idx_count: number, vtx_count: number)
* ImDrawList:PushClipRect(clip_rect_min_x: number, clip_rect_min_y: number, clip_rect_max_x: number, clip_rect_max_y: number, intersect_with_current_clip_rect: boolean = false)
* ImDrawList:PushClipRectFullScreen()
* ImDrawList:PushTextureID(texture_id: Image)
* ImDrawList:_ClearFreeMemory()
* ImDrawList:_OnChangedClipRect()
* ImDrawList:_OnChangedTextureID()
* ImDrawList:_OnChangedVtxOffset()
* ImDrawList:_PopUnusedDrawCmd()
* ImDrawList:_ResetForNewFrame()

### Unsupported methods (3)
* ImGui.AddCallback(callback, callback_data)
* ImGui.AddConvexPolyFilled(points, num_points, col)
* ImGui.AddPolyline(points, num_points, col, closed, thickness)

