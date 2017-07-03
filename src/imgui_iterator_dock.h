//IMGUI_API void BeginDockspace();
IMGUI_FUNCTION(BeginDockspace)
CALL_FUNCTION_NO_RET(BeginDockspace)
ADD_END_STACK(0)
END_IMGUI_FUNC
//IMGUI_API void EndDockspace();
IMGUI_FUNCTION(EndDockspace)
CALL_FUNCTION_NO_RET(EndDockspace)
POP_END_STACK(0)
END_IMGUI_FUNC
//IMGUI_API void ShutdownDock();
IMGUI_FUNCTION(ShutdownDock)
CALL_FUNCTION_NO_RET(ShutdownDock)
END_IMGUI_FUNC
//IMGUI_API void SetNextDock(ImGuiDockSlot slot);
IMGUI_FUNCTION(SetNextDock)
OPTIONAL_ENUM_ARG(slot, 6)
CALL_FUNCTION_NO_RET(SetNextDock, (ImGuiDockSlot)slot)
END_IMGUI_FUNC
//IMGUI_API bool BeginDock(const char* label, bool* opened = nullptr, ImGuiWindowFlags extra_flags = 0);
IMGUI_FUNCTION(BeginDock)
LABEL_ARG(label)
DEFAULT_ARG(bool*, opened, NULL)
OPTIONAL_ENUM_ARG(extra_flags, 0)
CALL_FUNCTION(BeginDock, bool, label, opened, extra_flags)
IF_RET_ADD_END_STACK(1)
PUSH_BOOL(ret)
END_IMGUI_FUNC
//IMGUI_API void SetNextDockSplitRatio(const ImVec2& split_ratio = ImVec2 0.5  0.5);
IMGUI_FUNCTION(SetNextDockSplitRatio)
OPTIONAL_IM_VEC_2_ARG(split_ratio, 0.5 , 0.5)
CALL_FUNCTION_NO_RET(SetNextDockSplitRatio, split_ratio)
END_IMGUI_FUNC
//IMGUI_API void SetNextDockFloatingSize(const ImVec2& floating_size = ImVec2 0.5  0.5);
IMGUI_FUNCTION(SetNextDockFloatingSize)
OPTIONAL_IM_VEC_2_ARG(floating_size, 0.5 , 0.5)
CALL_FUNCTION_NO_RET(SetNextDockFloatingSize, floating_size)
END_IMGUI_FUNC
//IMGUI_API void EndDock();
IMGUI_FUNCTION(EndDock)
CALL_FUNCTION_NO_RET(EndDock)
POP_END_STACK(1)
END_IMGUI_FUNC
//IMGUI_API void SetDockActive();
IMGUI_FUNCTION(SetDockActive)
CALL_FUNCTION_NO_RET(SetDockActive)
END_IMGUI_FUNC
//IMGUI_API void DockDebugWindow();
IMGUI_FUNCTION(DockDebugWindow)
CALL_FUNCTION_NO_RET(DockDebugWindow)
END_IMGUI_FUNC
END_STACK_START
END_STACK_OPTION(0, EndDockspace)
END_STACK_OPTION(1, EndDock)
END_STACK_END
