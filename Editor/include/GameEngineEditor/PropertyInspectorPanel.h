#pragma once
#include "imgui.h"
#include <vector>
#include "ReflectedVar.h"
#include "ReflectedVarRenderer.h"
#include "Entity.h"

namespace Editor {

	void RenderProperties(std::vector<Reflect::Var>& VarsToRender) {

		for (auto& Var : VarsToRender)
		{
			Editor::RenderVar(Var);
		}
		
	};

	void RenderComponentsPanel(Engine::Entity& SelectedEntity) {

		ImGuiWindowFlags PropertyPanelFlags = ImGuiWindowFlags_AlwaysHorizontalScrollbar | /*ImGuiWindowFlags_NoMove |*/ ImGuiWindowFlags_NoCollapse;
		ImGui::Begin("Property inspector", (bool*)0, PropertyPanelFlags);

		for (auto& Comp : SelectedEntity.m_Components)
		{
			if (ImGui::CollapsingHeader(Comp->ComponentType.c_str())) {
				RenderProperties(Comp->ExportedProperties);
			}
		}

		ImGui::End();
	}
}
