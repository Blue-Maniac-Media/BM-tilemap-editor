#include "BMTE.hpp"
#include "imgui.h"
#include "raylib.h"
#include "rlImGui.h"

void BMTE::Run()
{
    // main loop
    Init();
    while (!WindowShouldClose()) 
    {
        Update();
        Draw();
    }
    Close();
}

// ================================================================================

void BMTE::Init()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(640, 480, "BMTE");
    SetTargetFPS(60);
    rlImGuiSetup(true);
}

void BMTE::Update()
{
    // logic
}

void BMTE::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

        rlImGuiBegin();
            ImGui::Begin("Inspector");
                ImGui::Text("BMTE");
            ImGui::End();
        rlImGuiEnd();

    EndDrawing();
}

void BMTE::Close()
{
    rlImGuiShutdown();
    CloseWindow();
}
