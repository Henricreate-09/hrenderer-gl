cmake_minimum_required(VERSION 4.1)

set(PROJ_NAME Game)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CXX_STANDARD 17)

project(${PROJ_NAME})

# Got any problem here "senior" dev?
file(GLOB_RECURSE SOURCE_FILES 
    CONFIGURE_DEPENDS
    Src/*.cpp
    Src/*.c
)


find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(${PROJ_NAME} ${SOURCE_FILES})
target_include_directories(${PROJ_NAME} PRIVATE ./Include)
target_link_libraries(${PROJ_NAME} PRIVATE OpenGL::GL glfw)