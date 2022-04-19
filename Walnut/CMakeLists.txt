cmake_minimum_required(VERSION 3.1)

add_library(walnut STATIC src/Image.cpp src/Application.cpp src/ImGui/ImGuiBuild.cpp)
if (DEFINED WL_DIST)
    add_executable(walnut_app WIN32 EntryPoint.cpp)
else()
    add_executable(walnut_app EntryPoint.cpp)
endif()
target_link_libraries(walnut imgui glfw3)
add_subdirectory(user_src)

target_include_directories(walnut PUBLIC src/include)



target_link_libraries(walnut_app walnut walnut_user)

if(DEFINED WL_DIST)
    set(CMAKE_EXE_LINKER_FLAGS
            "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:WinMainCRTStartup /subsystem:windows")
    add_definitions(-DWL_DIST=1)
endif()
