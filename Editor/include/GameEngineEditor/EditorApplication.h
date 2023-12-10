#pragma once
#include "Application.h"
#include <memory>
#include "TreeNode.h"
#include "AssetBrowser.h"

#include "ReflectedVar.h"
#include "EditorTypes.h"
#include "ReflectedVarRenderer.h"
#include "SDL.h"
#include "imgui.h"
#include <stdio.h>
#include "imgui_impl_sdlrenderer2.h"
#include "imgui_impl_sdl2.h"

#include "World.h"
#include "Entity.h"

class EditorApplication : public Application
{

public:
    EditorApplication() {};
    ~EditorApplication();

private:
    SDL_Window* window{ nullptr };
    SDL_Renderer* renderer{ nullptr };
    ImGuiIO* io{ nullptr };

private:
    void Startup();
    void Loop();
    void InputLoop();

    void LoadScene(std::string InFilePath);

    void ConvertTreeNodesToEcsNodes(Editor::TreeNode& RootNode);
    void SaveScene(std::string OutFilePath);
    
    // Our state
    bool show_demo_window = true;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    std::vector<Reflect::Var> ReflVars;

    Engine::World EcsWorld{};
    //Editor::TreeNode TreeNodeRoot{ "Root", (void*)(EcsWorld.RootEntity.get()) };

    std::unique_ptr<Editor::TreeNode> TreeNodeRoot = std::make_unique<Editor::TreeNode>("Root", (void*) (EcsWorld.RootEntity.get()));

    Editor::AssetBrowser s_AssetBrowser{};
  

    
};

