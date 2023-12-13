#include "AssetBrowser.h"
#include <filesystem>
#include <iostream>
#include "imgui.h"




void Editor::AssetBrowser::DrawFiles()
{
    static std::filesystem::path CurrentPath{ BuildDirPath };
    

    if (ImGui::Button("<-") and CurrentPath.has_parent_path() and CurrentPath != BuildDirPath) {
        CurrentPath = CurrentPath.parent_path();
    }

    for (auto& dir_entry : std::filesystem::directory_iterator{ CurrentPath }) {

     
        bool FileNodeOpen = ImGui::Selectable(dir_entry.path().filename().string().c_str(), SelectedDirPath == dir_entry.path());

        if (FileNodeOpen) {
            SelectedDirPath = dir_entry.path();
        }
        if (FileNodeOpen and dir_entry.is_directory()) {
            CurrentPath = dir_entry.path();
            
        }

        if (ImGui::BeginDragDropSource()) {

            CurrentPayload._SentFile = dir_entry;

            ImGui::SetDragDropPayload("FILE", (void*) &CurrentPayload , sizeof(CurrentPayload));
            
            std::filesystem::path DraggedFile = std::filesystem::relative(dir_entry.path(), BuildDirPath);
            ImGui::Text(DraggedFile.string().c_str());

            ImGui::EndDragDropSource();
        }

    }
    

}


void Editor::AssetBrowser::Render()
{
    ImGuiWindowFlags AssetBrowserFlags = ImGuiWindowFlags_AlwaysHorizontalScrollbar | /*ImGuiWindowFlags_NoMove |*/ ImGuiWindowFlags_NoCollapse;
    ImGui::Begin("Asset Browser", (bool*)0, AssetBrowserFlags);
    DrawFiles();
    ImGui::End();
}
