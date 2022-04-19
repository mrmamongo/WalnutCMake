cmake_minimum_required(VERSION 3.1)
project(imgui LANGUAGES CXX)

add_library(imgui_static STATIC imgui.cpp imgui_draw.cpp
        imgui_widgets.cpp imgui_tables.cpp imgui_demo.cpp
        backends/imgui_impl_vulkan.cpp backends/imgui_impl_glfw.cpp)

target_include_directories(imgui_static PUBLIC include backends ${GLFW_INCLUDE_DIRS})

target_link_libraries(imgui_static glfw3 Vulkan::Vulkan Vulkan::Headers)
add_library(imgui ALIAS imgui_static)
