#!/bin/bash

cd bindings_generator
perl generate_imgui_bindings.pl <../src/libimgui/imgui.h >../src/imgui_iterator.inl
