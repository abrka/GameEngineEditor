include(FetchContent)


FetchContent_Declare(
  entt
  GIT_REPOSITORY https://github.com/skypjack/entt.git
)
FetchContent_MakeAvailable(entt)


FetchContent_Declare(
  nlohmann_json
  URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)


FetchContent_Declare(
  guid
  GIT_REPOSITORY https://github.com/graeme-hill/crossguid.git
)
FetchContent_MakeAvailable(guid)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)


