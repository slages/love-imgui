# LOVE-IMGUI

A partial rewrite of [slage's](https://github.com/slages/love-imgui) bindings to the [imgui](https://github.com/ocornut/imgui). This is not compatible, and makes deviations in API design!

## Getting Started

Just build the project, and copy the generated dynamic module next to your love executable or into the LÖVE application data folder (for instance "C:/Users/<user>/AppData/Roaming/LOVE" on Windows or ~/.local/shared/love on Linux).

Pre-built binaries for Windows and Mas OSX are provided in the [releases](https://github.com/slages/love-imgui/releases) page.

## Differences

* New bindings generator implementation. While not an explicit API difference, the output may diverge unintentionally!
* return order is out-parameters first, return value last. This is not configurable.
* We're taking a maximalist approach to enums. All of these are valid and interchangable with no configuration necessary:
```lua
imgui.Begin("MyWindow", true, "AlwaysAutoResize|NoTitleBar")
imgui.Begin("MyWindow", true, {"AlwaysAutoResize", "NoTitleBar"})
imgui.Begin("MyWindow", true, {AlwaysAutoResize = true, NoTitleBar = true})
```

## Examples

Simple integration:
```lua
require "imgui"

local showTestWindow = false
local showAnotherWindow = false
local floatValue = 0
local sliderFloat = { 0.1, 0.5 }
local clearColor = { 0.2, 0.2, 0.2 }
local comboSelection = 1
local textValue = "text"

--
-- LOVE callbacks
--
function love.load(arg)
end

function love.update(dt)
    imgui.NewFrame()
end

function love.draw()

    -- Menu
    if imgui.BeginMainMenuBar() then
        if imgui.BeginMenu("File") then
            imgui.MenuItem("Test")
            imgui.EndMenu()
        end
        imgui.EndMainMenuBar()
    end

    -- Debug window
    imgui.Text("Hello, world!")
    clearColor[1], clearColor[2], clearColor[3] = imgui.ColorEdit3("Clear color", clearColor[1], clearColor[2], clearColor[3])
    
    -- Sliders
    floatValue = imgui.SliderFloat("SliderFloat", floatValue, 0.0, 1.0)
    sliderFloat[1], sliderFloat[2] = imgui.SliderFloat2("SliderFloat2", sliderFloat[1], sliderFloat[2], 0.0, 1.0)
    
    -- Combo
    comboSelection = imgui.Combo("Combo", comboSelection, { "combo1", "combo2", "combo3", "combo4" }, 4)

    -- Windows
    if imgui.Button("Test Window") then
        showTestWindow = not showTestWindow
    end
    
    if imgui.Button("Another Window") then
        showAnotherWindow = not showAnotherWindow
    end
    
    if showAnotherWindow then
        imgui.SetNextWindowPos(50, 50, "FirstUseEver")
        showAnotherWindow = imgui.Begin("Another Window", true, "AlwaysAutoResize|NoTitleBar")
        imgui.Text("Hello")
        -- Input text
        textValue = imgui.InputTextMultiline("InputText", textValue, 200, 300, 200)
        imgui.End()
    end

    if showTestWindow then
        showTestWindow = imgui.ShowDemoWindow(true)
    end

    love.graphics.clear(clearColor)
    imgui.Render()
end

function love.quit()
    imgui.ShutDown()
end

--
-- User inputs
--
function love.textinput(t)
    imgui.TextInput(t)
    if not imgui.GetWantCaptureKeyboard() then
        -- Pass event to the game
    end
end

function love.keypressed(key)
    imgui.KeyPressed(key)
    if not imgui.GetWantCaptureKeyboard() then
        -- Pass event to the game
    end
end

function love.keyreleased(key)
    imgui.KeyReleased(key)
    if not imgui.GetWantCaptureKeyboard() then
        -- Pass event to the game
    end
end

function love.mousemoved(x, y)
    imgui.MouseMoved(x, y)
    if not imgui.GetWantCaptureMouse() then
        -- Pass event to the game
    end
end

function love.mousepressed(x, y, button)
    imgui.MousePressed(button)
    if not imgui.GetWantCaptureMouse() then
        -- Pass event to the game
    end
end

function love.mousereleased(x, y, button)
    imgui.MouseReleased(button)
    if not imgui.GetWantCaptureMouse() then
        -- Pass event to the game
    end
end

function love.wheelmoved(x, y)
    imgui.WheelMoved(y)
    if not imgui.GetWantCaptureMouse() then
        -- Pass event to the game
    end
end
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

