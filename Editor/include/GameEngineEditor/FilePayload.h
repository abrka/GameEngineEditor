#pragma once

namespace Editor {

	struct FilePayload {
		std::filesystem::path _BuildDirPath{};
		std::filesystem::path _SentFile{};
	};
}