#pragma once


namespace Editor {

    class TreeNode;

    class EntityNodeRenderer {
    public:
        Editor::TreeNode* SelectedNode = nullptr;
        void Render(Editor::TreeNode& RootNode);
    };
}
