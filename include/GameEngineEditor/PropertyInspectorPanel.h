#pragma once
#include "imgui.h"
#include <vector>
#include "ReflectedVar.h"
#include "ReflectedVarRenderer.h"
#include "Entity.h"

namespace Editor {

	void RenderProperties(std::vector<Reflect::Var>& VarsToRender) {

		ImGuiWindowFlags PropertyPanelFlags = ImGuiWindowFlags_AlwaysHorizontalScrollbar | /*ImGuiWindowFlags_NoMove |*/ ImGuiWindowFlags_NoCollapse;
		ImGui::Begin("Property inspector", (bool*)0, PropertyPanelFlags);

		for (auto& Var : VarsToRender)
		{
			Editor::RenderVar(Var);
		}
		ImGui::End();
	};

	void RenderComponentsPanel(Engine::Entity& SelectedEntity) {

		for (auto& Comp : SelectedEntity.m_Components)
		{
			if (ImGui::CollapsingHeader(Comp->ComponentType.c_str())) {
				RenderProperties(Comp->ExportedProperties);
			}
		}
	}
}
