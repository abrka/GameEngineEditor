#pragma once
#include <filesystem>
#include "FilePayload.h"

namespace Editor {

    class AssetBrowser
    {
    public:
        AssetBrowser() {};
        void Render();
    private:
        void DrawFiles();
        const std::filesystem::path BuildDirPath{ std::filesystem::current_path() };
        std::filesystem::path SelectedDirPath{ BuildDirPath };

        FilePayload CurrentPayload{BuildDirPath};
    };
}
