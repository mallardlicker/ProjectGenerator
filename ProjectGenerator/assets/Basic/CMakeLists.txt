# pgName

cmake_minimum_required(VERSION 3.22)

# ==================================================================================================
#	pgName Project
# ==================================================================================================
project(
    pgName
    VERSION 0.0.1
    DESCRIPTION "Description here."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# ==================================================================================================
#   Collect pgName project files
# ==================================================================================================

file(   GLOB_RECURSE pgName_SOURCE_FILES
    ${pgName_SOURCE_DIR}/cpp/*.cpp
)

file(   GLOB_RECURSE pgName_HEADER_FILES
    ${pgName_SOURCE_DIR}/include/*.h
)

set(pgName_INCLUDE_DIRS "${pgName_SOURCE_DIR}/include")

# Automatically add all subdirectories within include/
file(GLOB INCLUDE_SUBDIRS LIST_DIRECTORIES true "${pgName_SOURCE_DIR}/include/*")
foreach(SUBDIR ${INCLUDE_SUBDIRS})
    if(IS_DIRECTORY ${SUBDIR})
        list(APPEND pgName_INCLUDE_DIRS ${SUBDIR})
    endif()
endforeach()


# ==================================================================================================
#   Create generated executable
# ==================================================================================================

add_executable(pgAppOrStl 
               ${pgName_SOURCE_FILES} 
               ${pgName_HEADER_FILES})

target_include_directories(pgAppOrStl PRIVATE ${pgName_INCLUDE_DIRS})

target_compile_definitions(pgAppOrStl PRIVATE 
    $<$<CONFIG:Debug>:DEBUG_BUILD=1>
    $<$<CONFIG:Debug>:RELEASE_BUILD=0>
    $<$<CONFIG:Release>:DEBUG_BUILD=0>
    $<$<CONFIG:Release>:RELEASE_BUILD=1>
)