# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.25.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++.exe")
set(CMAKE_BUILD_TYPE Release)

project ("DeeperCXX")

add_executable(Main main.cpp)
set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/source)

target_include_directories(Main PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../headers/include>
    $<INSTALL_INTERFACE:headers>
)

#exec_program(Main ${CMAKE_CURRENT_BINARY_DIR}/source)