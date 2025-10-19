set (CMAKE_CXX_STANDARD 20)

project(
    EcsSerializerExample
    VERSION 0.0.1
)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE Main.cpp)

target_link_libraries(${PROJECT_NAME}
                      PUBLIC Engine)


