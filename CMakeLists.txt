cmake_minimum_required(VERSION 3.20.0)

project(Game VERSION 1.2)

set(SFML_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1)

# message(-----> ${SFML_ROOT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SFML_DIR ${SFML_ROOT_DIR}/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

add_executable(${PROJECT_NAME} 
source/main.cpp
source/data_base.cpp
source/editorial_place.cpp
source/button.cpp
source/text_button.cpp
source/m_button.cpp
source/app.cpp
source/menu.cpp
source/main_functions.cpp
source/gui.cpp
source/background.cpp 
source/object_rect_data.cpp 
source/base_object.cpp
source/stone.cpp 
source/map.cpp 
source/region.cpp
source/player.cpp
source/last_stop.cpp
source/texture_rect_player_data.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-network sfml-graphics sfml-audio)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/dllFiles/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX _V${CMAKE_PROJECT_VERSION}_${Configuration}.exe)

