cmake_minimum_required(VERSION 3.16)
project(Walnut_Cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

set(Vulkan_INCLUDE_DIRS "C:\\VulkanSDK\\1.3.211.0\\Include")
set(Vulkan_LIBRARIES "C:\\VulkanSDK\\1.3.211.0\\Lib")
find_package(Vulkan REQUIRED)

set(GLFW_INCLUDE_DIRS "C:\\glfw-3.3.7\\include")
set(GLFW_LIBRARIES "C:\\glfw-3.3.7\\")
add_library(glfw3 SHARED IMPORTED)
set_target_properties(glfw3 PROPERTIES IMPORTED_LOCATION "C:\\GLFW\\lib-vc2019\\glfw3.dll")
set_target_properties(glfw3 PROPERTIES IMPORTED_IMPLIB "C:\\glfw-3.3.7\\glfw3.lib")

add_subdirectory(third_party/glm)
add_subdirectory(third_party/imgui)
include_directories(third_party/stb_image)
add_subdirectory(Walnut)
