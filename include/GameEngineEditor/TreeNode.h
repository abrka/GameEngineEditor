#pragma once
#include <vector>
#include <string>
#include <memory>
#include <string_view>
#include "imgui.h"

namespace Editor {


    class TreeNode {

    public:
        TreeNode(std::string_view _Name , void* _AssociatedObject = nullptr) : Name(_Name), AssociatedObject(_AssociatedObject) {};
        std::string Name{};
        TreeNode* Parent = nullptr;
        void* AssociatedObject = nullptr;

        std::vector < std::unique_ptr<TreeNode>> Children;

        ImGuiTreeNodeFlags ImGuiFlags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
        std::string GetImguiID() const;

        void DestroyNode();
        void AddChild(std::unique_ptr<Editor::TreeNode>&& Child);

    private:
        void RemoveThisFromParentsChildren();

    };


}
