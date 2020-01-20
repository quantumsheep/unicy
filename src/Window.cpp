#include <unicy/Window.hpp>

using namespace Unicy;
using namespace Unicy::UI;

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

Window::Window(const int &width, const int &height, const char *title, const size_t &antialiasing, const bool &debug, GLFWmonitor *monitor, GLFWwindow *share) 
    : width(width), height(height), antialiasing(antialiasing), monitor(monitor), share(share)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        this->error = EnvironmentError::FailedToInitializeGLFW;
        return;
    }

    glfwWindowHint(GLFW_SAMPLES, antialiasing);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, debug ? GL_TRUE : GL_FALSE);
    glfwWindowHint(GLFW_SRGB_CAPABLE, GL_TRUE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->window = glfwCreateWindow(width, height, title, monitor, share);
    if (this->window == nullptr)
    {
        this->error = EnvironmentError::FailedToCreateWindow;
        return;
    }

    glfwMakeContextCurrent(this->window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        this->error = EnvironmentError::FailedToLoadGLAD;

        glfwTerminate();
        return;
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    // glFrontFace(GL_CCW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(this->window, true);
    ImGui_ImplOpenGL3_Init("#version 410");
}

bool Window::next_frame() const {
    if (this->window_should_close())
        return false;

    glClearColor(this->background.r, this->background.g, this->background.b, this->background.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwPollEvents();

    return true;
}

void Window::update_viewport()
{
    glfwGetFramebufferSize(this->window, &this->width, &this->height);
    glViewport(0, 0, this->width, this->height);
}
