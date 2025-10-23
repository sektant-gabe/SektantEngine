#include "SKT/GameLoop.h"
#include "imgui.h"

namespace SKT {

void GameLoop()
{
    if (ImGui::Begin("Main")) {
        ImGui::Text("ENGINE DOS CRIAS!!!!");
        ImGui::ShowDemoWindow();
        ImGui::End();
    }
}
};// namespace SKT
