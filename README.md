# LOVE-IMGUI

[imgui](https://github.com/ocornut/imgui) module for the [LÖVE](https://love2d.org/) game engine including lua bindings based on this [project](https://github.com/patrickriordan/imgui_lua_bindings).

It uses imgui 1.50 and supports 259 functions (40 unsupported), and is based on LÖVE 0.10.2.

It also includes the docks extension by @adcox (https://github.com/adcox/imgui).

## Getting Started

Just build the project, and copy the generated dynamic module next to your love executable or into the LÖVE application data folder (for instance "C:/Users/<user>/AppData/Roaming/LOVE" on Windows or ~/.local/shared/love on Linux).

Pre-built binaries are provided in the [releases](https://github.com/slages/love-imgui/releases) page.

## Examples

Simple integration:
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
        imgui.SetNextWindowPos(50, 50, "FirstUseEver")
        status, showAnotherWindow = imgui.Begin("Another Window", true, { "AlwaysAutoResize", "NoTitleBar" });
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

Docks:
```lua
require "imgui"

--
-- LOVE callbacks
--
function love.load(arg)
end

function love.update(dt)
    imgui.NewFrame()
end

function love.draw()
    imgui.SetNextWindowPos(0, 0)
    imgui.SetNextWindowSize(love.graphics.getWidth(), love.graphics.getHeight())
    if imgui.Begin("DockArea", nil, { "NoTitleBar", "NoResize", "NoMove", "NoBringToFrontOnFocus" }) then
        imgui.BeginDockspace()

        -- Create 10 docks
        for i = 1, 10 do
            if imgui.BeginDock("dock_"..i) then
                imgui.Text("Hello, dock "..i.."!");
            end
            imgui.EndDock()
        end

        imgui.EndDockspace()
    end
    imgui.End()

    love.graphics.clear(100, 100, 100, 255)
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
end

function love.keypressed(key)
    imgui.KeyPressed(key)
end

function love.keyreleased(key)
    imgui.KeyReleased(key)
end

function love.mousemoved(x, y)
    imgui.MouseMoved(x, y)
end

function love.mousepressed(x, y, button)
    imgui.MousePressed(button)
end

function love.mousereleased(x, y, button)
    imgui.MouseReleased(button)
end

function love.wheelmoved(x, y)
    imgui.WheelMoved(y)
end
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

