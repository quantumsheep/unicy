#pragma once

#include <unicy/ui/ImGui.hpp>

namespace Unicy::UI
{

template <typename Function>
void Window(const char *name, ImGuiWindowFlags flags, Function body)
{
    UI::Begin(name, nullptr, flags);

    body();

    UI::End();
}

template <typename Function>
inline void Window(const char *name, Function body)
{
    return UI::Window(name, 0, body);
}

} // namespace Unicy::UI