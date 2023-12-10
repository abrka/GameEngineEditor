#pragma once
#include <vector>
#include <string>
#include <memory>
#include <string_view>
#include "imgui.h"
#include "Entity.h"

namespace Editor {

    
    class TreeNode {
    public:
        TreeNode(std::string_view _Name , Engine::Entity&  _AssociatedEntity) : Name(_Name), AssociatedObject(_AssociatedEntity) {};

        std::string Name{};
        TreeNode* Parent = nullptr;
        Engine::Entity& AssociatedObject;

        std::vector < std::unique_ptr<TreeNode>> Children;

        ImGuiTreeNodeFlags ImGuiFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
        std::string GetImguiID() const;

        void DestroyNode();
        void AddChild(std::unique_ptr<Editor::TreeNode>&& Child);

    private:
        void RemoveThisFromParentsChildren();

    };


}
