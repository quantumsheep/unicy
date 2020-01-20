#pragma once

#include <iostream>
#include <unicy/ui/ImGui.hpp>

namespace Unicy::UI
{
template <typename Function>
void MenuBar(Function body)
{
    if (UI::BeginMenuBar())
    {
        body();
        UI::EndMenuBar();
    }
}

template <typename Function>
void Menu(const char *name, Function body)
{
    if (UI::BeginMenu(name))
    {
        body();
        UI::EndMenu();
    }
}

template <typename Function>
void MenuItem(const char *name, const char *shortcut, Function execute)
{
    if (ImGui::MenuItem(name, shortcut))
        execute();
}

} // namespace UI
