cmake_minimum_required(VERSION 3.28)
project(ray-tracing)

set(SourceFiles
    src/main.cpp
    src/window.cpp)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ${SourceFiles})

target_link_libraries(${PROJECT_NAME} 
    SDL2::SDL2)
