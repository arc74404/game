cmake_minimum_required(VERSION 3.20.0)

project(Game VERSION 1.2)

set(SFML_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1)

# message(-----> ${SFML_ROOT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SFML_DIR ${SFML_ROOT_DIR}/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

add_executable(${PROJECT_NAME} 
source/app/main.cpp
source/app/app.cpp
source/gui/gui.cpp
source/gui/background.cpp 
source/objects/map/object_rect_data.cpp 
source/objects/map/base_object.cpp
source/objects/map/stone.cpp 
source/objects/map/map.cpp 
source/objects/map/region.cpp
source/objects/player/player.cpp
source/objects/player/last_stop.cpp
source/objects/player/texture_rect_data.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-network sfml-graphics sfml-audio)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/dllFiles/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX _V${CMAKE_PROJECT_VERSION}_${Configuration}.exe)

