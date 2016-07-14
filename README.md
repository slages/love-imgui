# LOVE-IMGUI

[imgui](https://github.com/ocornut/imgui) module for the [löve](https://love2d.org/) game engine including lua bindings based on this [project](https://github.com/patrickriordan/imgui_lua_bindings).

It uses imgui 1.50 WIP and supports 250 functions (48 unsupported), and is based on the latest löve sources.

## Getting Started

Merge the content of this repository with the löve source repository and build löve as usual.

So far it was only tested with löve Windows build.

## Example

```lua
require "imgui"

local showTestWindow = false
local showAnotherWindow = false
local floatValue = 0;
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
    local status

    -- Menu
    if imgui.BeginMainMenuBar() then
        if imgui.BeginMenu("File") then
            imgui.MenuItem("Test")
            imgui.EndMenu()
        end
        imgui.EndMainMenuBar()
    end

    -- Debug window
    imgui.Text("Hello, world!");
    status, clearColor[1], clearColor[2], clearColor[3] = imgui.ColorEdit3("Clear color", clearColor[1], clearColor[2], clearColor[3]);
    
    -- Sliders
    status, floatValue = imgui.SliderFloat("SliderFloat", floatValue, 0.0, 1.0);
    status, sliderFloat[1], sliderFloat[2] = imgui.SliderFloat2("SliderFloat2", sliderFloat[1], sliderFloat[2], 0.0, 1.0);
    
    -- Combo
    status, comboSelection = imgui.Combo("Combo", comboSelection, { "combo1", "combo2", "combo3", "combo4" }, 4);

    -- Windows
    if imgui.Button("Test Window") then
        showTestWindow = not showTestWindow;
    end
    
    if imgui.Button("Another Window") then
        showAnotherWindow = not showAnotherWindow;
    end
    
    if showAnotherWindow then
        imgui.SetNextWindowPos(50, 50, ImGuiSetCond_FirstUseEver)
        status, showAnotherWindow = imgui.Begin("Another Window", true, ImGuiWindowFlags_AlwaysAutoResize);
        imgui.Text("Hello");
        -- Input text
        status, textValue = imgui.InputTextMultiline("InputText", textValue, 200, 300, 200);
        imgui.End();
    end

    if showTestWindow then
        showTestWindow = imgui.ShowTestWindow(true)
    end

    love.graphics.clear(clearColor[1] * 255, clearColor[2] * 255, clearColor[3] * 255, 255)
    imgui.Render();
end

function love.quit()
    imgui.ShutDown();
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

