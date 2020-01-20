#include <unicy/unicy.hpp>

using namespace Unicy;

int main()
{
    auto window = Window(1280, 720, "Freecam Example");

    if (window.error != EnvironmentError::None)
    {
        Debug::Log(stderr, "An error occured: %d\n", window.error);
        return 1;
    }

    while (window.next_frame())
    {
        UI::NewFrame();

        UI::Window("Debug", [&] {
            UI::Separator();

            static bool wireframe = false;
            UI::Checkbox("Wireframe", &wireframe);

            ImGui::ColorEdit4("Background", window.background);

            glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
        });

        UI::Render();
        UI::Draw();

        window.update_viewport();
        window.swap_buffers();
    }

    return 0;
}
