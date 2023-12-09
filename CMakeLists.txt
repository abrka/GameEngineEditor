cmake_minimum_required(VERSION 3.20)

project(GameEngineEditor
    VERSION 0.0.1
    LANGUAGES C CXX
    DESCRIPTION "a game engine editor"
    )

set (CMAKE_CXX_STANDARD 20)


add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
                PRIVATE src/EditorMain.cpp                       
                        src/Application.cpp 
                        src/AssetBrowser.cpp 
                        src/EditorApplication.cpp 
                        src/EditorMain.cpp 
                        src/ReflectedVarRenderer.cpp 
                        src/TreeNode.cpp 
                        src/TreeNodeRenderer.cpp 
                                             
                        include/GameEngineEditor/Application.h 
                        include/GameEngineEditor/AssetBrowser.h 
                        include/GameEngineEditor/EditorApplication.h 
                        include/GameEngineEditor/ReflectedVarRenderer.h 
                        include/GameEngineEditor/TreeNode.h 
                        include/GameEngineEditor/TreeNodeRenderer.h
                        include/GameEngineEditor/HierarchyEntityPanel.h
                        include/GameEngineEditor/PropertyInspectorPanel.h)



target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GameEngineEditor>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2main)

add_subdirectory(external)
target_link_libraries(imgui SDL2::SDL2)
target_link_libraries(imgui SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} imgui::imgui)

# include(FetchContent)
# FetchContent_Declare(
#   EcsLib
#   GIT_REPOSITORY https://github.com/abcdedafjkdmme/EcsSerializer.git
# )
# FetchContent_MakeAvailable(EcsLib)

add_subdirectory(external/ecs)
target_link_libraries(${PROJECT_NAME} EcsSerializerLib)


