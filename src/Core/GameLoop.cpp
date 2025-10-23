#include "imgui.h"

#include "GameLoop.h"

void GameLoop()
{
    if (ImGui::Begin("Main"))
    {
        ImGui::Text("ENGINE DOS CRIAS!!!!");
        ImGui::ShowDemoWindow();
        ImGui::End();
    }
}
