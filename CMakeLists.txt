cmake_minimum_required(VERSION 3.2) # Project Version
project(sdl_renderer_boilerplate) # Project Name
set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/") # Project Path
cmake_policy(SET CMP0079 NEW)

# SDL2
find_package(SDL2 REQUIRED) # Find Package from cmake/FindSDL2.cmake
include_directories(${SDL2_INCLUDE_DIR})

# SDL2_IMAGE
find_package(SDL2_image REQUIRED) # Find Package from cmake/FindSDL2_image.cmake
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Add source directory
add_subdirectory(src)

# Linking Sources
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES}) # SDL2 Source
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_IMAGE_LIBRARIES}) # SDL2 IMAGE Source
