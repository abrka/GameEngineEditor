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

	bool IsCompEntityMarker(Engine::Component& Comp) {
		return dynamic_cast<Engine::EntityMarker*>(&Comp) != nullptr;
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
				//we do not show the entity marker component in editor. it is for internal engine purposes
				if (not IsCompEntityMarker(*Comp)) {

					if (ImGui::CollapsingHeader(GetComponentImguiId(*Comp).c_str(), &Comp->IsAliveInEditor, ImGuiTreeNodeFlags_DefaultOpen))
					{
						RenderProperties(Comp->ExportedProperties);
					}
				}


				if (not Comp->IsAliveInEditor) {
					Comp->RemoveThisComponentFromEntity(*Comp->Owner);

				}
			}

			if (ImGui::Button("[+] Add Component")) {
				ImGui::OpenPopup("AddComponentPopup");
			}

			if (ImGui::BeginPopup("AddComponentPopup"))
			{
				ImGui::SeparatorText("All Components");

				auto& ComponentFactory = SelectedEntity->m_World->m_CompFactory;
				const auto& RegisteredComponentsMap = ComponentFactory.CompMap;

				for (const auto& [ComponentTypeStr, Component] : RegisteredComponentsMap)
				{

					//again we do not show the entity marker component in editor. it is for internal engine purposes
					if (not IsCompEntityMarker(*Component)) {

						if (ImGui::Selectable(ComponentTypeStr.c_str())) {
							ComponentFactory.AddComponentFromType(ComponentTypeStr, *SelectedEntity);

						}
					}
				}
				ImGui::EndPopup();
			}

		}

		ImGui::End();



	}
}