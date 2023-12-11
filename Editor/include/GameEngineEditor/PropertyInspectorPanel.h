#pragma once
#include "imgui.h"
#include <vector>
#include "ReflectedVar.h"
#include "ReflectedVarRenderer.h"
#include "Entity.h"

namespace Editor {

	std::string GetComponentImguiId(Engine::Component& Comp) {
		return (Comp.ComponentType + "##" + reinterpret_cast<const char*>(&Comp));
	}

	void RenderProperties(std::vector<Reflect::Var>& VarsToRender) {

		for (auto& Var : VarsToRender)
		{
			Editor::RenderVar(Var);
		}

	};

	void RenderInspectorPanel(Engine::Entity* SelectedEntity) {

		ImGuiWindowFlags PropertyPanelFlags = ImGuiWindowFlags_AlwaysHorizontalScrollbar | /*ImGuiWindowFlags_NoMove |*/ ImGuiWindowFlags_NoCollapse;
		ImGui::Begin("Property inspector", (bool*)0, PropertyPanelFlags);

		if (SelectedEntity) {

			for (auto& Comp : SelectedEntity->m_Components)
			{
				if (ImGui::CollapsingHeader(GetComponentImguiId(*Comp).c_str(), &Comp->IsAliveInEditor, ImGuiTreeNodeFlags_DefaultOpen)) {

					RenderProperties(Comp->ExportedProperties);

				}

				//entt doesnt delete the component instantly. it takes a few frames. so we use QueuedForDeletion to prevnt double free errors
				if ((not Comp->IsAliveInEditor) and (not Comp->QueuedForDeletion)) {
					Comp->QueuedForDeletion = true;
					Comp->RemoveThisComponentFromEntity(*Comp->Owner);

				}
			}

			ImGui::Button("[+] Add Component");
		}

		ImGui::End();
	}


}
