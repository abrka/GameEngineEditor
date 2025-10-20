cmake_minimum_required(VERSION 3.12)

project(Engine
    VERSION 0.0.1
    LANGUAGES CXX
    )

set (CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC)


target_sources(${PROJECT_NAME} 
                PRIVATE src/ComponentFactory.cpp
                        src/Entity.cpp
                        src/World.cpp
                        src/WImage.cpp
                        include/EcsSerializer/Component.h
                        include/EcsSerializer/ComponentFactory.h
                        include/EcsSerializer/EngineComponents.h
                        include/EcsSerializer/Entity.h
                        include/EcsSerializer/World.h
                        include/EcsSerializer/ReflectedVar.h
                        include/EcsSerializer/WImage.h)



target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/EcsSerializer>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)



add_subdirectory(external)


target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2_image::SDL2_image)
target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PUBLIC EnTT::EnTT)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)
target_link_libraries(${PROJECT_NAME} PUBLIC crossguid) 

add_subdirectory(examples)
