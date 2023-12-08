cmake_minimum_required(VERSION 3.12)

project(GameEngineEditor
    VERSION 0.0.1
    LANGUAGES C CXX
    DESCRIPTION "a game engine editor"
    )

set (CMAKE_CXX_STANDARD 20)


target_sources(${PROJECT_NAME}
                PRIVATE src/EditorMain                       
                        src/Application
                        src/AssetBrowser
                        src/EditorApplication
                        src/EditorMain
                        src/ReflectedVarRenderer
                        src/TreeNode
                        src/TreeNodeRenderer)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngineEditor>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)


add_executable(${PROJECT_NAME})