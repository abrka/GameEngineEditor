cmake_minimum_required(VERSION 3.20)

project(imgui_proj)

add_library(imgui STATIC)

target_sources(imgui
                PRIVATE imgui-docking/imconfig.h
                imgui-docking/imgui_demo.cpp
                imgui-docking/imgui_draw.cpp
                imgui-docking/imgui_internal.h
                imgui-docking/imgui_tables.cpp 
                imgui-docking/imgui_widgets.cpp 
                imgui-docking/imgui.cpp 
                imgui-docking/imgui.h 
                imgui-docking/imstb_rectpack.h 
                imgui-docking/imstb_textedit.h 
                imgui-docking/imstb_truetype.h 
                imgui-docking/backends/imgui_impl_sdl2.h
                imgui-docking/backends/imgui_impl_sdl2.cpp
                imgui-docking/backends/imgui_impl_sdlrenderer2.h
                imgui-docking/backends/imgui_impl_sdlrenderer2.cpp
                imgui-docking/misc/cpp/imgui_stdlib.cpp 
                imgui-docking/misc/cpp/imgui_stdlib.h 
                        )

target_include_directories(
    imgui
    PUBLIC $<BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/imgui-docking/backends ${CMAKE_CURRENT_SOURCE_DIR}/imgui-docking ${CMAKE_CURRENT_SOURCE_DIR}/imgui-docking/misc/cpp>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
           
target_link_libraries(imgui SDL2::SDL2)
target_link_libraries(imgui SDL2::SDL2main)