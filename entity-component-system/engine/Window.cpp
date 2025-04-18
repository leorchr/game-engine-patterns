#include "Window.h"
#include "raylib.h"

Window::Window(i32 widthP, i32 heightP, str titleP):
width { widthP },
height { heightP },
title { std::move(titleP) }
{
    InitWindow(width, height, title.c_str());
}

Window::~Window() {
    CloseWindow();
}

bool Window::ShouldClose() {
    return WindowShouldClose();
}