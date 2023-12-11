#pragma once
#include <vector>
#include <string>
#include <memory>
#include <string_view>
#include "imgui.h"
#include "Entity.h"
#include "EngineComponents.h"

namespace Editor {

    
    class TreeNode {
    public:
        TreeNode( Engine::Entity&  _AssociatedEntity) :  AssociatedObject(_AssociatedEntity){};

        Engine::Entity& AssociatedObject;
        std::string& Name = AssociatedObject.GetComponent<Engine::Name>().StrName;

        TreeNode* Parent = nullptr;
        std::vector < std::unique_ptr<TreeNode>> Children;

        ImGuiTreeNodeFlags ImGuiFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
        std::string GetImguiID() const;

        void DestroyNode();
        void AddChild(std::unique_ptr<Editor::TreeNode>&& Child);

    private:
        void RemoveThisFromParentsChildren();

    };


}
