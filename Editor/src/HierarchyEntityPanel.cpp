#include "HierarchyEntityPanel.h"
#include "TreeNode.h"

void Editor::HierarchyEntityPanel::Render(Engine::World& EcsWorld, Editor::TreeNode& RootNode)
{


	ImGuiWindowFlags TreePanelFlags = ImGuiWindowFlags_AlwaysHorizontalScrollbar | /*ImGuiWindowFlags_NoMove |*/ ImGuiWindowFlags_NoCollapse;

	ImGui::Begin("Tree panel", (bool*)0, TreePanelFlags);


	bool AddNodeButtonClicked = ImGui::Button("[+] Add Tree Node");
	ImGui::SameLine();
	bool RemoveNodeButtonClicked = ImGui::Button("[-] Remove Tree Node");

	s_TreeNodeRenderer.Render(RootNode);

	if (AddNodeButtonClicked and s_TreeNodeRenderer.SelectedNode != nullptr) {

		/*std::unique_ptr<Engine::Entity> CreatedEntity = ;*/

		s_TreeNodeRenderer.SelectedNode->AssociatedObject.AddChild(EcsWorld.CreateEntity());

		auto& MovedEntity = s_TreeNodeRenderer.SelectedNode->AssociatedObject.Children.back();

		s_TreeNodeRenderer.SelectedNode->AddChild(std::make_unique<Editor::TreeNode>("Added tree node", *MovedEntity));
		s_TreeNodeRenderer.SelectedNode->ImGuiFlags |= ImGuiTreeNodeFlags_DefaultOpen;
	}

	if (RemoveNodeButtonClicked && s_TreeNodeRenderer.SelectedNode != nullptr) {

		
		s_TreeNodeRenderer.SelectedNode->AssociatedObject.DestroyEntity();
		s_TreeNodeRenderer.SelectedNode->DestroyNode();
		/*s_TreeNodeRenderer.SelectedNode->AssociatedObject = nullptr;*/
		s_TreeNodeRenderer.SelectedNode = nullptr;

	}


	ImGui::End();

}
