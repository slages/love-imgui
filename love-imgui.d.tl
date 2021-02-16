local type ImGui = record
    ShutDown: function
    NewFrame: function
    Render: function
    MouseMoved: function(x: number, y: number)
    MousePressed: function(button: number)
    MouseReleased: function(button: number)
    WheelMoved: function(y: number)
    KeyPressed: function(key: string)
    KeyReleased: function(key: string)
    TextInput: function(text: string)
    GetWantCaptureMouse: function(): boolean
    GetWantCaptureKeyboard: function(): boolean
    GetWantTextInput: function(): boolean
    SetGlobalFontFromFileTTF: function(path: string, size_pixels: number,
        spacing_x: number, spacing_y: number, oversample_x: number,
        oversample_y: number)
    ----- GENERATED PART ----- 
    blah():1
    blah():2
    blah():3
    blah():4
    blah():5
    blah():6
    blah():7
    blah():8
    blah():9
    blah():10

    ----- END OF GENERATED PART ----- 
end

return ImGui
