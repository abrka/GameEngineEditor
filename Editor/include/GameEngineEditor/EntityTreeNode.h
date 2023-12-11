#pragma once
#include "imgui.h"
#include "Entity.h"
#include <string>

class EntityTreeNode: Engine::Entity {

public:
	std::string Name{};
	ImGuiTreeNodeFlags ImGuiFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
	
	std::string GetImguiID()const {
		return std::string{ Name + "##" + reinterpret_cast<const char*>(this) };
	};
};