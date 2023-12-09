#pragma once
#include "imgui.h"
#include "TreeNodeRenderer.h"

namespace Editor {

    static Editor::TreeNodeRenderer s_TreeNodeRenderer{};
   

	void RenderHierarchyEntityPanel(std::unique_ptr<Editor::TreeNode>& RootNode) {

        ImGuiWindowFlags TreePanelFlags = ImGuiWindowFlags_AlwaysHorizontalScrollbar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;

        ImGui::Begin("Tree panel", (bool*)0, TreePanelFlags);


        bool AddNodeButtonClicked = ImGui::Button("[+] Add Tree Node");
        ImGui::SameLine();
        bool RemoveNodeButtonClicked = ImGui::Button("[-] Remove Tree Node");

        s_TreeNodeRenderer.Render(*RootNode);

        if (AddNodeButtonClicked and s_TreeNodeRenderer.SelectedNode != nullptr) {
            s_TreeNodeRenderer.SelectedNode->AddChild(std::make_unique<Editor::TreeNode>("Added tree node"));
            s_TreeNodeRenderer.SelectedNode->ImGuiFlags |= ImGuiTreeNodeFlags_DefaultOpen;
        }

        if (RemoveNodeButtonClicked && s_TreeNodeRenderer.SelectedNode != nullptr) {

            s_TreeNodeRenderer.SelectedNode->RemoveFromParent();
            s_TreeNodeRenderer.SelectedNode = nullptr;
            
        }


        ImGui::End();
	}
}