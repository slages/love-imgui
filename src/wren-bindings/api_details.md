This file was automatically generated on Tue Oct 13 03:36:20 2020, UTC
# ImGui

### Supported methods (207)
* ImGui.AlignTextToFramePadding()
* ImGui.ArrowButton(str_id, dir)
* ImGui.Begin(name, p_open = NULL, flags = 0)
* ImGui.BeginChildFrame(id, size, flags = 0)
* ImGui.BeginCombo(label, preview_value, flags = 0)
* ImGui.BeginDragDropSource(flags = 0)
* ImGui.BeginDragDropTarget()
* ImGui.BeginGroup()
* ImGui.BeginMainMenuBar()
* ImGui.BeginMenu(label, enabled = true)
* ImGui.BeginMenuBar()
* ImGui.BeginPopup(str_id, flags = 0)
* ImGui.BeginPopupModal(name, p_open = NULL, flags = 0)
* ImGui.BeginTabBar(str_id, flags = 0)
* ImGui.BeginTabItem(label, p_open = NULL, flags = 0)
* ImGui.BeginTooltip()
* ImGui.Bullet()
* ImGui.BulletText(fmt)
* ImGui.Button(label, size = ImVec2(0, 0))
* ImGui.CalcItemWidth()
* ImGui.CalcListClipping(items_count, items_height, out_items_display_start, out_items_display_end)
* ImGui.CalcTextSize(text, text_end = NULL, hide_text_after_double_hash = false, wrap_width = -1.0f)
* ImGui.CaptureKeyboardFromApp(want_capture_keyboard_value = true)
* ImGui.CaptureMouseFromApp(want_capture_mouse_value = true)
* ImGui.Checkbox(label, v)
* ImGui.CheckboxFlags(label, flags, flags_value)
* ImGui.CloseCurrentPopup()
* ImGui.ColorButton(desc_id, col, flags = 0, size = ImVec2(0, 0))
* ImGui.ColorConvertU32ToFloat4(input)
* ImGui.Columns(count = 1, id = NULL, border = true)
* ImGui.DestroyPlatformWindows()
* ImGui.DockSpace(id, size = ImVec2(0, 0), flags = 0, window_class = NULL)
* ImGui.DockSpaceOverViewport(viewport = NULL, flags = 0, window_class = NULL)
* ImGui.Dummy(size)
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
* ImGui.GetClipboardText()
* ImGui.GetColumnIndex()
* ImGui.GetColumnOffset(column_index = -1)
* ImGui.GetColumnWidth(column_index = -1)
* ImGui.GetColumnsCount()
* ImGui.GetContentRegionAvail()
* ImGui.GetContentRegionMax()
* ImGui.GetCursorPos()
* ImGui.GetCursorPosX()
* ImGui.GetCursorPosY()
* ImGui.GetCursorScreenPos()
* ImGui.GetCursorStartPos()
* ImGui.GetFontSize()
* ImGui.GetFontTexUvWhitePixel()
* ImGui.GetFrameCount()
* ImGui.GetFrameHeight()
* ImGui.GetFrameHeightWithSpacing()
* ImGui.GetItemRectMax()
* ImGui.GetItemRectMin()
* ImGui.GetItemRectSize()
* ImGui.GetKeyIndex(imgui_key)
* ImGui.GetKeyPressedAmount(key_index, repeat_delay, rate)
* ImGui.GetMouseCursor()
* ImGui.GetMouseDragDelta(button = 0, lock_threshold = -1.0f)
* ImGui.GetMousePos()
* ImGui.GetMousePosOnOpeningCurrentPopup()
* ImGui.GetScrollMaxX()
* ImGui.GetScrollMaxY()
* ImGui.GetScrollX()
* ImGui.GetScrollY()
* ImGui.GetStyleColorName(idx)
* ImGui.GetStyleColorVec4(idx)
* ImGui.GetTextLineHeight()
* ImGui.GetTextLineHeightWithSpacing()
* ImGui.GetTime()
* ImGui.GetTreeNodeToLabelSpacing()
* ImGui.GetVersion()
* ImGui.GetWindowContentRegionMax()
* ImGui.GetWindowContentRegionMin()
* ImGui.GetWindowContentRegionWidth()
* ImGui.GetWindowDockID()
* ImGui.GetWindowDpiScale()
* ImGui.GetWindowHeight()
* ImGui.GetWindowPos()
* ImGui.GetWindowSize()
* ImGui.GetWindowWidth()
* ImGui.Indent(indent_w = 0.0f)
* ImGui.InputDouble(label, v, step = 0.0, step_fast = 0.0, format = "%.6f", flags = 0)
* ImGui.InputFloat(label, v, step = 0.0f, step_fast = 0.0f, format = "%.3f", flags = 0)
* ImGui.InputInt(label, v, step = 1, step_fast = 100, flags = 0)
* ImGui.IsAnyItemActive()
* ImGui.IsAnyItemFocused()
* ImGui.IsAnyItemHovered()
* ImGui.IsAnyMouseDown()
* ImGui.IsItemActivated()
* ImGui.IsItemActive()
* ImGui.IsItemClicked(mouse_button = 0)
* ImGui.IsItemDeactivated()
* ImGui.IsItemDeactivatedAfterEdit()
* ImGui.IsItemEdited()
* ImGui.IsItemFocused()
* ImGui.IsItemHovered(flags = 0)
* ImGui.IsItemToggledOpen()
* ImGui.IsItemVisible()
* ImGui.IsKeyDown(user_key_index)
* ImGui.IsKeyPressed(user_key_index, repeat = true)
* ImGui.IsKeyReleased(user_key_index)
* ImGui.IsMouseClicked(button, repeat = false)
* ImGui.IsMouseDoubleClicked(button)
* ImGui.IsMouseDown(button)
* ImGui.IsMouseDragging(button, lock_threshold = -1.0f)
* ImGui.IsMouseHoveringRect(r_min, r_max, clip = true)
* ImGui.IsMouseReleased(button)
* ImGui.IsWindowAppearing()
* ImGui.IsWindowCollapsed()
* ImGui.IsWindowDocked()
* ImGui.IsWindowFocused(flags = 0)
* ImGui.IsWindowHovered(flags = 0)
* ImGui.LabelText(label, fmt)
* ImGui.ListBoxFooter()
* ImGui.LoadIniSettingsFromDisk(ini_filename)
* ImGui.LogButtons()
* ImGui.LogFinish()
* ImGui.LogText(fmt)
* ImGui.LogToClipboard(auto_open_depth = -1)
* ImGui.LogToFile(auto_open_depth = -1, filename = NULL)
* ImGui.LogToTTY(auto_open_depth = -1)
* ImGui.NewFrame()
* ImGui.NewLine()
* ImGui.NextColumn()
* ImGui.PopAllowKeyboardFocus()
* ImGui.PopButtonRepeat()
* ImGui.PopClipRect()
* ImGui.PopFont()
* ImGui.PopID()
* ImGui.PopItemWidth()
* ImGui.PopStyleColor(count = 1)
* ImGui.PopStyleVar(count = 1)
* ImGui.PopTextWrapPos()
* ImGui.ProgressBar(fraction, size_arg = ImVec2(-1, 0), overlay = NULL)
* ImGui.PushAllowKeyboardFocus(allow_keyboard_focus)
* ImGui.PushButtonRepeat(repeat)
* ImGui.PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect)
* ImGui.PushItemWidth(item_width)
* ImGui.PushTextWrapPos(wrap_local_pos_x = 0.0f)
* ImGui.Render()
* ImGui.ResetMouseDragDelta(button = 0)
* ImGui.SameLine(offset_from_start_x = 0.0f, spacing = -1.0f)
* ImGui.SaveIniSettingsToDisk(ini_filename)
* ImGui.Separator()
* ImGui.SetClipboardText(text)
* ImGui.SetColorEditOptions(flags)
* ImGui.SetColumnOffset(column_index, offset_x)
* ImGui.SetColumnWidth(column_index, width)
* ImGui.SetCursorPos(local_pos)
* ImGui.SetCursorPosX(local_x)
* ImGui.SetCursorPosY(local_y)
* ImGui.SetCursorScreenPos(pos)
* ImGui.SetItemAllowOverlap()
* ImGui.SetItemDefaultFocus()
* ImGui.SetKeyboardFocusHere(offset = 0)
* ImGui.SetMouseCursor(cursor_type)
* ImGui.SetNextItemOpen(is_open, cond = 0)
* ImGui.SetNextItemWidth(item_width)
* ImGui.SetNextWindowBgAlpha(alpha)
* ImGui.SetNextWindowCollapsed(collapsed, cond = 0)
* ImGui.SetNextWindowContentSize(size)
* ImGui.SetNextWindowDockID(dock_id, cond = 0)
* ImGui.SetNextWindowFocus()
* ImGui.SetNextWindowPos(pos, cond = 0, pivot = ImVec2(0, 0))
* ImGui.SetNextWindowSize(size, cond = 0)
* ImGui.SetNextWindowViewport(viewport_id)
* ImGui.SetScrollFromPosX(local_x, center_x_ratio = 0.5f)
* ImGui.SetScrollFromPosY(local_y, center_y_ratio = 0.5f)
* ImGui.SetScrollHereX(center_x_ratio = 0.5f)
* ImGui.SetScrollHereY(center_y_ratio = 0.5f)
* ImGui.SetScrollX(scroll_x)
* ImGui.SetScrollY(scroll_y)
* ImGui.SetTabItemClosed(tab_or_docked_window_label)
* ImGui.SetTooltip(fmt)
* ImGui.SetWindowFontScale(scale)
* ImGui.ShowAboutWindow(p_open = NULL)
* ImGui.ShowDemoWindow(p_open = NULL)
* ImGui.ShowFontSelector(label)
* ImGui.ShowMetricsWindow(p_open = NULL)
* ImGui.ShowStyleSelector(label)
* ImGui.ShowUserGuide()
* ImGui.SmallButton(label)
* ImGui.Spacing()
* ImGui.TabItemButton(label, flags = 0)
* ImGui.Text(fmt)
* ImGui.TextColored(col, fmt)
* ImGui.TextDisabled(fmt)
* ImGui.TextUnformatted(text, text_end = NULL)
* ImGui.TextWrapped(fmt)
* ImGui.TreePop()
* ImGui.Unindent(indent_w = 0.0f)
* ImGui.UpdatePlatformWindows()

### Unsupported methods (85)
* ImGui.AcceptDragDropPayload
* true
* ImGui.BeginPopupContextItem
* true
* ImGui.BeginPopupContextVoid
* true
* ImGui.BeginPopupContextWindow
* true
* ImGui.ColorEdit3
* true
* ImGui.ColorEdit4
* true
* ImGui.ColorPicker3
* true
* ImGui.ColorPicker4
* true
* ImGui.Combo
* true
* ImGui.CreateContext
* true
* ImGui.DestroyContext
* true
* ImGui.DragFloat
* true
* ImGui.DragFloat2
* true
* ImGui.DragFloat3
* true
* ImGui.DragFloat4
* true
* ImGui.DragFloatRange2
* true
* ImGui.DragInt
* true
* ImGui.DragInt2
* true
* ImGui.DragInt3
* true
* ImGui.DragInt4
* true
* ImGui.DragIntRange2
* true
* ImGui.FindViewportByID
* true
* ImGui.FindViewportByPlatformHandle
* true
* ImGui.GetBackgroundDrawList
* true
* ImGui.GetCurrentContext
* true
* ImGui.GetDragDropPayload
* true
* ImGui.GetDrawData
* true
* ImGui.GetDrawListSharedData
* true
* ImGui.GetFont
* true
* ImGui.GetForegroundDrawList
* true
* ImGui.GetID
* true
* ImGui.GetIO
* true
* ImGui.GetMainViewport
* true
* ImGui.GetPlatformIO
* true
* ImGui.GetStateStorage
* true
* ImGui.GetStyle
* true
* ImGui.GetWindowDrawList
* true
* ImGui.GetWindowViewport
* true
* ImGui.Image
* true
* ImGui.ImageButton
* true
* ImGui.InputFloat2
* true
* ImGui.InputFloat3
* true
* ImGui.InputFloat4
* true
* ImGui.InputInt2
* true
* ImGui.InputInt3
* true
* ImGui.InputInt4
* true
* ImGui.InputText
* true
* ImGui.InputTextMultiline
* true
* ImGui.InputTextWithHint
* true
* ImGui.InvisibleButton
* true
* ImGui.IsMousePosValid
* true
* ImGui.IsPopupOpen
* true
* ImGui.ListBox
* true
* ImGui.LoadIniSettingsFromMemory
* true
* ImGui.OpenPopup
* true
* ImGui.OpenPopupOnItemClick
* true
* ImGui.PlotHistogram
* true
* ImGui.PlotLines
* true
* ImGui.PushFont
* true
* ImGui.PushID
* true
* ImGui.RenderPlatformWindowsDefault
* true
* ImGui.SaveIniSettingsToMemory
* true
* ImGui.SetCurrentContext
* true
* ImGui.SetDragDropPayload
* true
* ImGui.SetNextWindowClass
* true
* ImGui.SetNextWindowSizeConstraints
* true
* ImGui.SetStateStorage
* true
* ImGui.ShowStyleEditor
* true
* ImGui.SliderAngle
* true
* ImGui.SliderFloat
* true
* ImGui.SliderFloat2
* true
* ImGui.SliderFloat3
* true
* ImGui.SliderFloat4
* true
* ImGui.SliderInt
* true
* ImGui.SliderInt2
* true
* ImGui.SliderInt3
* true
* ImGui.SliderInt4
* true
* ImGui.StyleColorsClassic
* true
* ImGui.StyleColorsDark
* true
* ImGui.StyleColorsLight
* true
* ImGui.TreeNode
* true
* ImGui.TreeNodeEx
* true
* ImGui.TreePush
* true
* ImGui.VSliderFloat
* true
* ImGui.VSliderInt
* true

# ImDrawList

### Supported methods (0)

### Unsupported methods (0)

