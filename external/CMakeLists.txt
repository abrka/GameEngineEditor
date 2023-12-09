cmake_minimum_required(VERSION 3.20)

project(imgui)

add_library(imgui)
add_library(imgui::imgui ALIAS imgui)

target_sources(imgui
                PRIVATE imgui/imconfig.h
                        imgui/imgui_demo.cpp
                        imgui/imgui_draw.cpp
                        imgui/imgui_internal.h
                        imgui/imgui_tables.cpp 
                        imgui/imgui_widgets.cpp 
                        imgui/imgui.cpp 
                        imgui/imgui.h 
                        imgui/imstb_rectpack.h 
                        imgui/imstb_textedit.h 
                        imgui/imstb_truetype.h 
                        imgui/backends/imgui_impl_sdl2.h
                        imgui/backends/imgui_impl_sdl2.cpp
                        imgui/backends/imgui_impl_sdlrenderer2.h
                        imgui/backends/imgui_impl_sdlrenderer2.cpp
                        imgui/misc/cpp/imgui_stdlib.cpp 
                        imgui/misc/cpp/imgui_stdlib.h 
                        )

target_include_directories(
    imgui
    PUBLIC $<BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends ${CMAKE_CURRENT_SOURCE_DIR}/imgui ${CMAKE_CURRENT_SOURCE_DIR}/imgui/misc/cpp>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)