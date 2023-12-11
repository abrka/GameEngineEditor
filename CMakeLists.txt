cmake_minimum_required(VERSION 3.20)

project(EngineAndEditor)

add_subdirectory(Engine)
add_subdirectory(Editor)

target_link_libraries(GameEngineEditor Engine)