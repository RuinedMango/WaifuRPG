cmake_minimum_required(VERSION 3.9.1)
project(WaifuRPG)

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

set( GLFW-CMAKE-STARTER-SRC
        src/main.cpp
)

include_directories(libs/GLFW/include)
include_directories(libs/OpenAL/include)
find_package(Vulkan REQUIRED)
add_subdirectory(libs/GLFW)
add_subdirectory(libs/OpenAL)
add_executable(WaifuRPG src/main.cpp)
target_link_libraries(WaifuRPG Vulkan::Vulkan)
target_link_libraries(WaifuRPG glfw)
target_link_libraries(WaifuRPG OpenAL)