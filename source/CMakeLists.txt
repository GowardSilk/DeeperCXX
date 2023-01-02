# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.25.1)
project ("DeeperCXX")

#-------------------------EXT_PACKAGES------------------------
#  DOXYGEN
find_package(DOXYGEN)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
#  DOXYGEN
#------------------------!EXT_PACKAGES------------------------

#--------------------------VARIABLES--------------------------
#   COMPILER SETTINGS
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++.exe")
#  !COMPILER SETTINGS

#   BUILD SETTINGS
set(CMAKE_BUILD_TYPE Release)
set(CUSTOM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../headers/include)
set(CUSTOM_SRC_ALGOS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../algos)
set(CUSTOM_BIN_ALGOS_DIR ${CMAKE_CURRENT_BINARY_DIR}/../algos)
set(COMPILE_CHALLENGES FALSE) #set this var to true, if you want to recompile challenges
if(COMPILE_CHALLENGES)
    set(LIST_ALGOS_LOGS 
            Log1 
            Log2 
            Log3 
            Log4 
            Log5 
            Log6 
            Log7 
            Log8
        )
    foreach(i IN LISTS LIST_ALGOS_LOGS)
        list (
            APPEND add_custom_target_args
            COMMAND $<TARGET_FILE:${i}>
            RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_SRC_ALGOS_DIR}
        )
        add_executable(
            ${i} #Log[i]
            ${CUSTOM_SRC_ALGOS_DIR}/${i}.cpp #Log[i].cpp
        )
        set_target_properties(
            ${i}
            PROPERTIES LINKER_LANGUAGE CXX
            RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_BIN_ALGOS_DIR}
        )
        target_link_libraries(${i} DEEP_LIB)
    endforeach()
    set(LIST_ALGOS_REACTOR 
            Reactor1 
            Reactor2
            Reactor3
            Reactor4
            Reactor5
            Reactor6
            Reactor7
            Reactor8
            Reactor9
            Reactor10
        )
    foreach(i IN LISTS LIST_ALGOS_REACTOR)
        list (
            APPEND add_custom_target_args
            COMMAND $<TARGET_FILE:${i}>
            RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_SRC_ALGOS_DIR}
        )
        add_executable(
            ${i} #Log[i]
            ${CUSTOM_SRC_ALGOS_DIR}/${i}.cpp #Log[i].cpp
        )
        set_target_properties(
            ${i}
            PROPERTIES LINKER_LANGUAGE CXX
            RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_BIN_ALGOS_DIR}
        )
        target_link_libraries(${i} DEEP_LIB)
    endforeach()
endif()
add_executable(Main main.cpp)
set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/source)
target_link_libraries(Main DEEP_LIB)
#   !BUILD SETTINGS
#-------------------------!VARIABLES--------------------------

#------------------------LIBRARY_CONFIG-----------------------
add_library(DEEP_LIB ${CUSTOM_INCLUDE_DIR})
set_target_properties(DEEP_LIB PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(DEEP_LIB PUBLIC ${CUSTOM_INCLUDE_DIR})
add_custom_target(LIST_ALGOS_LOGS
    ${add_custom_target_args}
)
#-----------------------!LIBRARY_CONFIG-----------------------

# target_include_directories(Main PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../headers/include>
#     $<INSTALL_INTERFACE:headers>
# )
# target_include_directories(LIST_ALGOS_LOGS PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../headers/include>
#     $<INSTALL_INTERFACE:headers>
# )

exec_program(Main ${CMAKE_CURRENT_BINARY_DIR}/source)