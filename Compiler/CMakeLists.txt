cmake_minimum_required(VERSION 3.0)
project(compiler)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")

file(GLOB_RECURSE SRC RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.cpp" "src/*.hpp")
add_executable(compiler ${SRC})
set_target_properties(compiler PROPERTIES POSITION_INDEPENDENT_CODE ON)
add_definitions("-D_FILE_OFFSET_BITS=64")

add_library(bstrlib STATIC "lib/bstrlib/bstrwrap.cpp" "lib/bstrlib/bstraux.c" "lib/bstrlib/bstrlib.c" "lib/bstrlib/buniutil.c" "lib/bstrlib/utf8util.c" "lib/bstrlib/bsafe.c")
target_include_directories(bstrlib INTERFACE "lib/bstrlib")
set_target_properties(bstrlib PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(compiler PRIVATE bstrlib)
