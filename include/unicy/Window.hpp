#pragma once

#include <unicy/EnvironmentError.hpp>
#include <unicy/Color.hpp>
#include <unicy/gl.hpp>
#include <unicy/ui/ImGui.hpp>

#include <memory>
#include <string>

namespace Unicy
{

class Window
{
public:
    EnvironmentError error = EnvironmentError::None;

    int width;
    int height;

    int antialiasing;
    bool debug;

    GLFWwindow *window;

    GLFWmonitor *monitor = nullptr;
    GLFWwindow *share = nullptr;

    Color background = Color(0.75f, 0.15f, 0.15f, 1.0f);

    Window(const int &width, const int &height, const char *title, const size_t &antialiasing = 1, const bool &debug = false, GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr);

    inline bool window_should_close() const
    {
        return (bool)glfwWindowShouldClose(this->window);
    }

    inline void swap_buffers() const
    {
        glfwSwapBuffers(this->window);
    }

    bool Window::next_frame() const;
    void Window::update_viewport();
};

} // namespace Unicy
