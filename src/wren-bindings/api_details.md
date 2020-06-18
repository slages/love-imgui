# toplevel

### Supported methods (69)
* 	foreign static SetColumnOffset(column_index, offset_x)
* 	foreign static IsItemDeactivatedAfterEdit()
* 	foreign static IsMouseDoubleClicked(button)
* 	foreign static GetTreeNodeToLabelSpacing()
* 	foreign static SetNextItemOpen(is_open)
	foreign static SetNextItemOpen(is_open, cond)
* 	foreign static PopTextWrapPos()
* 	foreign static EndDragDropSource()
* 	foreign static GetWindowWidth()
* 	foreign static SetNextWindowCollapsed(collapsed)
	foreign static SetNextWindowCollapsed(collapsed, cond)
* 	foreign static TextWrapped(fmt)
* 	foreign static GetStyleColorName(idx)
* 	foreign static ColorButton(desc_id, col)
	foreign static ColorButton(desc_id, col, flags)
	foreign static ColorButton(desc_id, col, flags, size)
* 	foreign static SmallButton(label)
* 	foreign static IsMouseClicked(button)
	foreign static IsMouseClicked(button, repeat)
* 	foreign static BeginPopupContextWindow()
	foreign static BeginPopupContextWindow(str_id)
	foreign static BeginPopupContextWindow(str_id, mouse_button)
	foreign static BeginPopupContextWindow(str_id, mouse_button, also_over_items)
* 	foreign static Checkbox(label, v)
* 	foreign static InputFloat(label, v)
	foreign static InputFloat(label, v, step)
	foreign static InputFloat(label, v, step, step_fast)
	foreign static InputFloat(label, v, step, step_fast, format)
	foreign static InputFloat(label, v, step, step_fast, format, flags)
* 	foreign static IsMouseDown(button)
* 	foreign static VSliderInt(label, size, v, v_min, v_max)
	foreign static VSliderInt(label, size, v, v_min, v_max, format)
* 	foreign static LogFinish()
* 	foreign static ShowFontSelector(label)
* 	foreign static SetScrollHereX()
	foreign static SetScrollHereX(center_x_ratio)
* 	foreign static PushAllowKeyboardFocus(allow_keyboard_focus)
* 	foreign static PopStyleVar()
	foreign static PopStyleVar(count)
* 	foreign static SetScrollHereY()
	foreign static SetScrollHereY(center_y_ratio)
* 	foreign static GetContentRegionMax()
* 	foreign static IsMouseDragging(button)
	foreign static IsMouseDragging(button, lock_threshold)
* 	foreign static IsKeyDown(user_key_index)
* 	foreign static GetColumnIndex()
* 	foreign static GetColumnOffset()
	foreign static GetColumnOffset(column_index)
* 	foreign static VSliderFloat(label, size, v, v_min, v_max)
	foreign static VSliderFloat(label, size, v, v_min, v_max, format)
	foreign static VSliderFloat(label, size, v, v_min, v_max, format, power)
* 	foreign static DockSpace(id)
	foreign static DockSpace(id, size)
	foreign static DockSpace(id, size, flags)
	foreign static DockSpace(id, size, flags, window_class)
* 	foreign static IsKeyPressed(user_key_index)
	foreign static IsKeyPressed(user_key_index, repeat)
* 	foreign static GetFontSize()
* 	foreign static SameLine()
	foreign static SameLine(offset_from_start_x)
	foreign static SameLine(offset_from_start_x, spacing)
* 	foreign static Begin(name)
	foreign static Begin(name, p_open)
	foreign static Begin(name, p_open, flags)
* 	foreign static BeginTooltip()
* 	foreign static BeginMenu(label)
	foreign static BeginMenu(label, enabled)
* 	foreign static ShowUserGuide()
* 	foreign static DragFloat(label, v)
	foreign static DragFloat(label, v, v_speed)
	foreign static DragFloat(label, v, v_speed, v_min)
	foreign static DragFloat(label, v, v_speed, v_min, v_max)
	foreign static DragFloat(label, v, v_speed, v_min, v_max, format)
	foreign static DragFloat(label, v, v_speed, v_min, v_max, format, power)
* 	foreign static BeginChildFrame(id, size)
	foreign static BeginChildFrame(id, size, flags)
* 	foreign static InputDouble(label, v)
	foreign static InputDouble(label, v, step)
	foreign static InputDouble(label, v, step, step_fast)
	foreign static InputDouble(label, v, step, step_fast, format)
	foreign static InputDouble(label, v, step, step_fast, format, flags)
* 	foreign static SetColumnWidth(column_index, width)
* 	foreign static UpdatePlatformWindows()
* 	foreign static IsWindowHovered()
	foreign static IsWindowHovered(flags)
* 	foreign static PopFont()
* 	foreign static ProgressBar(fraction)
	foreign static ProgressBar(fraction, size_arg)
	foreign static ProgressBar(fraction, size_arg, overlay)
* 	foreign static GetTextLineHeightWithSpacing()
* 	foreign static BeginTabBar(str_id)
	foreign static BeginTabBar(str_id, flags)
* 	foreign static GetWindowContentRegionMin()
* 	foreign static LoadIniSettingsFromDisk(ini_filename)
* 	foreign static EndGroup()
* 	foreign static SetClipboardText(text)
* 	foreign static IsWindowFocused()
	foreign static IsWindowFocused(flags)
* 	foreign static EndTabBar()
* 	foreign static Button(label)
	foreign static Button(label, size)
* 	foreign static BeginTabItem(label)
	foreign static BeginTabItem(label, p_open)
	foreign static BeginTabItem(label, p_open, flags)
* 	foreign static IsItemEdited()
* 	foreign static SetCursorPos(local_pos)
* 	foreign static GetClipboardText()
* 	foreign static GetMouseDragDelta()
	foreign static GetMouseDragDelta(button)
	foreign static GetMouseDragDelta(button, lock_threshold)
* 	foreign static GetMousePosOnOpeningCurrentPopup()
* 	foreign static GetMousePos()
* 	foreign static IsAnyMouseDown()
* 	foreign static ListBoxFooter()
* 	foreign static IsMouseHoveringRect(r_min, r_max)
	foreign static IsMouseHoveringRect(r_min, r_max, clip)
* 	foreign static DragFloatRange2(label, v_current_min, v_current_max)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, power)
* 	foreign static GetVersion()
* 	foreign static TextUnformatted(text)
	foreign static TextUnformatted(text, text_end)
* 	foreign static BeginMainMenuBar()
* 	foreign static IsAnyItemActive()
* 	foreign static GetKeyPressedAmount(key_index, repeat_delay, rate)
* 	foreign static IsKeyReleased(user_key_index)
* 	foreign static EndMenuBar()
* 	foreign static GetKeyIndex(imgui_key)
* 	foreign static ColorConvertU32ToFloat4(input)
* 	foreign static ShowAboutWindow()
	foreign static ShowAboutWindow(p_open)
* 	foreign static CheckboxFlags(label, flags, flags_value)
* 	foreign static GetFrameHeight()
* 	foreign static SetNextWindowFocus()
* 	foreign static GetWindowPos()
* 	foreign static DragIntRange2(label, v_current_min, v_current_max)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max)
* 	foreign static EndChildFrame()
* 	foreign static GetScrollY()
* 	foreign static SetNextWindowPos(pos)
	foreign static SetNextWindowPos(pos, cond)
	foreign static SetNextWindowPos(pos, cond, pivot)
* 	foreign static BeginPopupModal(name)
	foreign static BeginPopupModal(name, p_open)
	foreign static BeginPopupModal(name, p_open, flags)
* 	foreign static GetTime()
* 	foreign static BeginMenuBar()
* 	foreign static IsWindowDocked()
* 	foreign static GetFrameHeightWithSpacing()
* 	foreign static LogToTTY()
	foreign static LogToTTY(auto_open_depth)
* 	foreign static NextColumn()
* 	foreign static GetWindowSize()
* 	foreign static SetItemAllowOverlap()
* 	foreign static GetWindowHeight()
* 	foreign static IsWindowAppearing()
* 	foreign static EndCombo()
* 	foreign static GetItemRectSize()
* 	foreign static SetNextWindowSize(size)
	foreign static SetNextWindowSize(size, cond)
* 	foreign static GetItemRectMax()
* 	foreign static AlignTextToFramePadding()
* 	foreign static CloseCurrentPopup()
* 	foreign static LogToFile()
	foreign static LogToFile(auto_open_depth)
	foreign static LogToFile(auto_open_depth, filename)
* 	foreign static GetItemRectMin()
* 	foreign static IsAnyItemFocused()
* 	foreign static CaptureKeyboardFromApp()
	foreign static CaptureKeyboardFromApp(want_capture_keyboard_value)
* 	foreign static IsAnyItemHovered()
* 	foreign static EndFrame()
* 	foreign static BeginDragDropSource()
	foreign static BeginDragDropSource(flags)
* 	foreign static GetCursorPosY()
* 	foreign static IsItemDeactivated()
* 	foreign static SetCursorPosX(local_x)
* 	foreign static EndMenu()
* 	foreign static TextDisabled(fmt)
* 	foreign static IsItemActivated()
* 	foreign static Unindent()
	foreign static Unindent(indent_w)
* 	foreign static IsItemVisible()
* 	foreign static SetScrollX(scroll_x)
* 	foreign static IsItemFocused()
* 	foreign static PopButtonRepeat()
* 	foreign static IsItemClicked()
	foreign static IsItemClicked(mouse_button)
* 	foreign static PopAllowKeyboardFocus()
* 	foreign static SetScrollFromPosX(local_x)
	foreign static SetScrollFromPosX(local_x, center_x_ratio)
* 	foreign static ResetMouseDragDelta()
	foreign static ResetMouseDragDelta(button)
* 	foreign static SetWindowFontScale(scale)
* 	foreign static IsItemHovered()
	foreign static IsItemHovered(flags)
* 	foreign static SetNextWindowBgAlpha(alpha)
* 	foreign static ShowStyleSelector(label)
* 	foreign static SetKeyboardFocusHere()
	foreign static SetKeyboardFocusHere(offset)
* 	foreign static BeginDragDropTarget()
* 	foreign static PopClipRect()
* 	foreign static SetItemDefaultFocus()
* 	foreign static PushItemWidth(item_width)
* 	foreign static PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect)
* 	foreign static LogToClipboard()
	foreign static LogToClipboard(auto_open_depth)
* 	foreign static IsWindowCollapsed()
* 	foreign static IsMouseReleased(button)
* 	foreign static LogButtons()
* 	foreign static IsItemActive()
* 	foreign static Spacing()
* 	foreign static SetNextWindowDockID(dock_id)
	foreign static SetNextWindowDockID(dock_id, cond)
* 	foreign static NewLine()
* 	foreign static DockSpaceOverViewport()
	foreign static DockSpaceOverViewport(viewport)
	foreign static DockSpaceOverViewport(viewport, flags)
	foreign static DockSpaceOverViewport(viewport, flags, window_class)
* 	foreign static SetTabItemClosed(tab_or_docked_window_label)
* 	foreign static PushButtonRepeat(repeat)
* 	foreign static GetStyleColorVec4(idx)
* 	foreign static CalcItemWidth()
* 	foreign static SetCursorScreenPos(pos)
* 	foreign static EndChild()
* 	foreign static CaptureMouseFromApp()
	foreign static CaptureMouseFromApp(want_capture_mouse_value)
* 	foreign static GetColumnsCount()
* 	foreign static DestroyPlatformWindows()
* 	foreign static EndPopup()
* 	foreign static Columns()
	foreign static Columns(count)
	foreign static Columns(count, id)
	foreign static Columns(count, id, border)
* 	foreign static IsPopupOpen(str_id)
* 	foreign static Bullet()
* 	foreign static EndTooltip()
* 	foreign static InputInt(label, v)
	foreign static InputInt(label, v, step)
	foreign static InputInt(label, v, step, step_fast)
	foreign static InputInt(label, v, step, step_fast, flags)
* 	foreign static SliderAngle(label, v_rad)
	foreign static SliderAngle(label, v_rad, v_degrees_min)
	foreign static SliderAngle(label, v_rad, v_degrees_min, v_degrees_max)
	foreign static SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format)
* 	foreign static OpenPopupOnItemClick()
	foreign static OpenPopupOnItemClick(str_id)
	foreign static OpenPopupOnItemClick(str_id, mouse_button)
* 	foreign static SetScrollFromPosY(local_y)
	foreign static SetScrollFromPosY(local_y, center_y_ratio)
* 	foreign static GetColumnWidth()
	foreign static GetColumnWidth(column_index)
* 	foreign static PopStyleColor()
	foreign static PopStyleColor(count)
* 	foreign static GetFrameCount()
* 	foreign static GetWindowDpiScale()
* 	foreign static CalcListClipping(items_count, items_height, out_items_display_start, out_items_display_end)
* 	foreign static GetScrollMaxY()
* 	foreign static GetCursorScreenPos()
* 	foreign static EndMainMenuBar()
* 	foreign static SaveIniSettingsToDisk(ini_filename)
* 	foreign static BeginPopup(str_id)
	foreign static BeginPopup(str_id, flags)
* 	foreign static BeginPopupContextItem()
	foreign static BeginPopupContextItem(str_id)
	foreign static BeginPopupContextItem(str_id, mouse_button)
* 	foreign static GetCursorStartPos()
* 	foreign static SetTooltip(fmt)
* 	foreign static GetScrollMaxX()
* 	foreign static IsItemToggledOpen()
* 	foreign static GetCursorPosX()
* 	foreign static PopItemWidth()
* 	foreign static SetNextWindowContentSize(size)
* 	foreign static LogText(fmt)
* 	foreign static SetScrollY(scroll_y)
* 	foreign static End()
* 	foreign static SetNextItemWidth(item_width)
* 	foreign static TreePop()
* 	foreign static GetWindowContentRegionWidth()
* 	foreign static GetFontTexUvWhitePixel()
* 	foreign static PushTextWrapPos()
	foreign static PushTextWrapPos(wrap_local_pos_x)
* 	foreign static ArrowButton(str_id, dir)
* 	foreign static BeginPopupContextVoid()
	foreign static BeginPopupContextVoid(str_id)
	foreign static BeginPopupContextVoid(str_id, mouse_button)
* 	foreign static ShowMetricsWindow()
	foreign static ShowMetricsWindow(p_open)
* 	foreign static GetWindowDockID()
* 	foreign static SetCursorPosY(local_y)
* 	foreign static DragInt(label, v)
	foreign static DragInt(label, v, v_speed)
	foreign static DragInt(label, v, v_speed, v_min)
	foreign static DragInt(label, v, v_speed, v_min, v_max)
	foreign static DragInt(label, v, v_speed, v_min, v_max, format)
* 	foreign static NewFrame()
* 	foreign static SetColorEditOptions(flags)
* 	foreign static GetMouseCursor()
* 	foreign static PopID()
* 	foreign static BeginGroup()
* 	foreign static Indent()
	foreign static Indent(indent_w)
* 	foreign static SliderInt(label, v, v_min, v_max)
	foreign static SliderInt(label, v, v_min, v_max, format)
* 	foreign static EndTabItem()
* 	foreign static Separator()
* 	foreign static GetTextLineHeight()
* 	foreign static GetScrollX()
* 	foreign static OpenPopup(str_id)
* 	foreign static LabelText(label, fmt)
* 	foreign static BulletText(fmt)
* 	foreign static SetMouseCursor(cursor_type)
* 	foreign static Dummy(size)
* 	foreign static GetWindowContentRegionMax()
* 	foreign static CalcTextSize(text)
	foreign static CalcTextSize(text, text_end)
	foreign static CalcTextSize(text, text_end, hide_text_after_double_hash)
	foreign static CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width)
* 	foreign static SliderFloat(label, v, v_min, v_max)
	foreign static SliderFloat(label, v, v_min, v_max, format)
	foreign static SliderFloat(label, v, v_min, v_max, format, power)
* 	foreign static GetContentRegionAvail()
* 	foreign static BeginCombo(label, preview_value)
	foreign static BeginCombo(label, preview_value, flags)
* 	foreign static GetCursorPos()
* 	foreign static SetNextWindowViewport(viewport_id)
* 	foreign static Render()
* 	foreign static TextColored(col, fmt)
* 	foreign static ShowDemoWindow()
	foreign static ShowDemoWindow(p_open)
* 	foreign static InvisibleButton(str_id, size)
* 	foreign static EndDragDropTarget()
* 	foreign static Text(fmt)

### Unsupported methods (69)
* SetColumnOffset
* IsItemDeactivatedAfterEdit
* IsMouseDoubleClicked
* GetTreeNodeToLabelSpacing
* SetNextItemOpen
* PopTextWrapPos
* EndDragDropSource
* GetWindowWidth
* SetNextWindowCollapsed
* TextWrapped
* GetStyleColorName
* ColorButton
* SmallButton
* IsMouseClicked
* BeginPopupContextWindow
* Checkbox
* InputFloat
* IsMouseDown
* VSliderInt
* LogFinish
* ShowFontSelector
* SetScrollHereX
* PushAllowKeyboardFocus
* PopStyleVar
* SetScrollHereY
* GetContentRegionMax
* IsMouseDragging
* IsKeyDown
* GetColumnIndex
* GetColumnOffset
* VSliderFloat
* DockSpace
* IsKeyPressed
* GetFontSize
* SameLine
* Begin
* BeginTooltip
* BeginMenu
* ShowUserGuide
* DragFloat
* BeginChildFrame
* InputDouble
* SetColumnWidth
* UpdatePlatformWindows
* IsWindowHovered
* PopFont
* ProgressBar
* GetTextLineHeightWithSpacing
* BeginTabBar
* GetWindowContentRegionMin
* LoadIniSettingsFromDisk
* EndGroup
* SetClipboardText
* IsWindowFocused
* EndTabBar
* Button
* BeginTabItem
* IsItemEdited
* SetCursorPos
* GetClipboardText
* GetMouseDragDelta
* GetMousePosOnOpeningCurrentPopup
* GetMousePos
* IsAnyMouseDown
* ListBoxFooter
* IsMouseHoveringRect
* DragFloatRange2
* GetVersion
* TextUnformatted
* BeginMainMenuBar
* IsAnyItemActive
* GetKeyPressedAmount
* IsKeyReleased
* EndMenuBar
* GetKeyIndex
* ColorConvertU32ToFloat4
* ShowAboutWindow
* CheckboxFlags
* GetFrameHeight
* SetNextWindowFocus
* GetWindowPos
* DragIntRange2
* EndChildFrame
* GetScrollY
* SetNextWindowPos
* BeginPopupModal
* GetTime
* BeginMenuBar
* IsWindowDocked
* GetFrameHeightWithSpacing
* LogToTTY
* NextColumn
* GetWindowSize
* SetItemAllowOverlap
* GetWindowHeight
* IsWindowAppearing
* EndCombo
* GetItemRectSize
* SetNextWindowSize
* GetItemRectMax
* AlignTextToFramePadding
* CloseCurrentPopup
* LogToFile
* GetItemRectMin
* IsAnyItemFocused
* CaptureKeyboardFromApp
* IsAnyItemHovered
* EndFrame
* BeginDragDropSource
* GetCursorPosY
* IsItemDeactivated
* SetCursorPosX
* EndMenu
* TextDisabled
* IsItemActivated
* Unindent
* IsItemVisible
* SetScrollX
* IsItemFocused
* PopButtonRepeat
* IsItemClicked
* PopAllowKeyboardFocus
* SetScrollFromPosX
* ResetMouseDragDelta
* SetWindowFontScale
* IsItemHovered
* SetNextWindowBgAlpha
* ShowStyleSelector
* SetKeyboardFocusHere
* BeginDragDropTarget
* PopClipRect
* SetItemDefaultFocus
* PushItemWidth
* PushClipRect
* LogToClipboard
* IsWindowCollapsed
* IsMouseReleased
* LogButtons
* IsItemActive
* Spacing
* SetNextWindowDockID
* NewLine
* DockSpaceOverViewport
* SetTabItemClosed
* PushButtonRepeat
* GetStyleColorVec4
* CalcItemWidth
* SetCursorScreenPos
* EndChild
* CaptureMouseFromApp
* GetColumnsCount
* DestroyPlatformWindows
* EndPopup
* Columns
* IsPopupOpen
* Bullet
* EndTooltip
* InputInt
* SliderAngle
* OpenPopupOnItemClick
* SetScrollFromPosY
* GetColumnWidth
* PopStyleColor
* GetFrameCount
* GetWindowDpiScale
* CalcListClipping
* GetScrollMaxY
* GetCursorScreenPos
* EndMainMenuBar
* SaveIniSettingsToDisk
* BeginPopup
* BeginPopupContextItem
* GetCursorStartPos
* SetTooltip
* GetScrollMaxX
* IsItemToggledOpen
* GetCursorPosX
* PopItemWidth
* SetNextWindowContentSize
* LogText
* SetScrollY
* End
* SetNextItemWidth
* TreePop
* GetWindowContentRegionWidth
* GetFontTexUvWhitePixel
* PushTextWrapPos
* ArrowButton
* BeginPopupContextVoid
* ShowMetricsWindow
* GetWindowDockID
* SetCursorPosY
* DragInt
* NewFrame
* SetColorEditOptions
* GetMouseCursor
* PopID
* BeginGroup
* Indent
* SliderInt
* EndTabItem
* Separator
* GetTextLineHeight
* GetScrollX
* OpenPopup
* LabelText
* BulletText
* SetMouseCursor
* Dummy
* GetWindowContentRegionMax
* CalcTextSize
* SliderFloat
* GetContentRegionAvail
* BeginCombo
* GetCursorPos
* SetNextWindowViewport
* Render
* TextColored
* ShowDemoWindow
* InvisibleButton
* EndDragDropTarget
* Text
# ImDrawList

### Supported methods (0)

### Unsupported methods (0)
