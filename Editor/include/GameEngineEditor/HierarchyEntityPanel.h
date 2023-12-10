#pragma once
#include "imgui.h"
#include "EngineComponents.h"
#include "TreeNodeRenderer.h"

namespace Editor {


	class HierarchyEntityPanel {

	public:
		Editor::EntityNodeRenderer s_TreeNodeRenderer{};
		void Render(Engine::World& EcsWorld, Editor::TreeNode& RootNode);

	};
}