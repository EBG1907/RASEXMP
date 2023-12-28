# CMakeList.txt : CMake project for RasCMuafiyet, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Cproject")

# Add source to this project's executable.
add_executable (Cprojecte "main.c" "include/raygui.h" "circle.c" "circle.h" "linkedlist.c" "linkedlist.h"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cprojecte PROPERTY CXX_STANDARD 20)
endif()
target_include_directories(Cprojecte PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Cprojecte C:/Users/Burak/Desktop/sondeneme/Cproject/lib/raylib.lib winmm.lib)


# TODO: Add tests and install targets if needed.












