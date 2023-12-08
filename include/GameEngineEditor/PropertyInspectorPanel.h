#pragma once
#include "imgui.h"
#include <vector>
#include "ReflectedVar.h"
#include "ReflectedVarRenderer.h"

namespace Editor {
	void RenderPropertyPanel(std::vector<Reflect::Var>& VarsToRender) {
		ImGuiWindowFlags PropertyPanelFlags = ImGuiWindowFlags_AlwaysHorizontalScrollbar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
		ImGui::Begin("Property inspector", (bool*)0, PropertyPanelFlags);

		for (auto& Var : VarsToRender)
		{
			Editor::RenderVar(Var);
		}
		ImGui::End();
	};
}
