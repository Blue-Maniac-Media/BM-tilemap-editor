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

    ImGuiIO io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
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

            if(ImGui::BeginMainMenuBar())
            {
                if(ImGui::BeginMenu("File"))
                {
                    if(ImGui::MenuItem("New"))  {}
                    if(ImGui::MenuItem("Open")) {}
                    if(ImGui::MenuItem("Save")) {}
                    ImGui::Separator();
                    if(ImGui::MenuItem("Exit")) {}
                    ImGui::EndMenu();
                }
                if(ImGui::BeginMenu("Edit"))
                {
                    if(ImGui::MenuItem("Undo", "Ctrl+Z")) {}
                    if(ImGui::MenuItem("Redo", "Ctrl+Y")) {}
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }

            ImGuiViewport* viewport = ImGui::GetMainViewport();
            float menuBarHeight = ImGui::GetFrameHeight();

            ImGui::SetNextWindowPos({viewport->Pos.x, viewport->Pos.y + menuBarHeight});
            ImGui::SetNextWindowSize({viewport->Size.x, viewport->Size.y - menuBarHeight});
            
            ImGuiWindowFlags dockFlags = 
                ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoResize   | ImGuiWindowFlags_NoMove     |
                ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus |
                ImGuiWindowFlags_NoBackground;

                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0,0});

                ImGui::Begin("##DockSpace", nullptr, dockFlags);
                ImGui::PopStyleVar();
                    ImGui::DockSpace(ImGui::GetID("MainDockSpace"), {0,0},
                        ImGuiDockNodeFlags_PassthruCentralNode);
                ImGui::End();

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
