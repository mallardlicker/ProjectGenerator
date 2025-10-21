# pgName/pgAppOrStlName

cmake_minimum_required(VERSION 3.22)

# ==================================================================================================
#	PGAPPORSTLNAME Project
# ==================================================================================================
project(
    PGAPPORSTLNAME
    VERSION 0.0.1
    DESCRIPTION "Description Here Please."
    LANGUAGES CXX
)

# add function(s) to project
include(FetchContent)


# ==================================================================================================
#	Define settings and preprocessor macros
# ==================================================================================================

# Is system app asset storage being used?
# See Application::init() for internal implementation
set(USE_SYSTEM_APP_ASSET_STORAGE true)

# Define source and destination directories
set(ASSETS_APP_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/assets/app")
set(ASSETS_USER_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/assets/user")
set(ASSETS_APP_DEST "$ENV{HOME}/Library/Application Support/pgName")
set(ASSETS_USER_DEST "$ENV{HOME}/Library/Containers/pgName")

# Whether the application should export (copy) assets to system directories
# ! Only works in conjunction with USE_SYSTEM_APP_ASSET_STORAGE = true
set(EXPORT_SYSTEM_APP_ASSET_STORAGE true)

# Custom macros:
# set(MY_CUSTOM_BOOL false)


# ==================================================================================================
#   Collect PGAPPORSTLNAME project files
# ==================================================================================================

file(	GLOB_RECURSE PGAPPORSTLNAME_SOURCE_FILES
	${PGAPPORSTLNAME_SOURCE_DIR}/cpp/*.cpp
)

file(	GLOB_RECURSE PGAPPORSTLNAME_HEADER_FILES
    ${PGAPPORSTLNAME_SOURCE_DIR}/include/*.h
)

set(pgAppOrStlName_INCLUDE_DIRS "${PGAPPORSTLNAME_SOURCE_DIR}/include")

# Automatically add all subdirectories within include/
file(GLOB INCLUDE_SUBDIRS LIST_DIRECTORIES true "${PGAPPORSTLNAME_SOURCE_DIR}/include/*")
foreach(SUBDIR ${INCLUDE_SUBDIRS})
    if(IS_DIRECTORY ${SUBDIR})
        list(APPEND pgAppOrStlName_INCLUDE_DIRS ${SUBDIR})
    endif()
endforeach()


# ==================================================================================================
#   Collect PGAPPORSTLNAME external library files
# ==================================================================================================

#   non-downloaded (FetchContent calls)

# GLFW
FetchContent_Declare(
	glfw 
	GIT_REPOSITORY https://github.com/glfw/glfw.git 
	GIT_TAG master
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# GLAD
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG v0.1.36
)
set(GLAD_PROFILE "core" CACHE STRING "" FORCE)
set(GLAD_API "gl=4.6" CACHE STRING "" FORCE)
set(GLAD_GENERATOR "c" CACHE STRING "" FORCE)
FetchContent_MakeAvailable(glad)

# GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
)
FetchContent_MakeAvailable(glm)

# CppUtils
FetchContent_Declare(
    CppUtils
    GIT_REPOSITORY https://github.com/mallardlicker/CppUtils.git
    GIT_TAG main
)
FetchContent_MakeAvailable(CppUtils)

# EnTT
FetchContent_Declare(
    EnTT
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG v3.13.2
)
FetchContent_MakeAvailable(EnTT)


#   downloaded (physical libraries)

# call find_package for locally (user) installed packages like glfw or OpenGL
# GLFW (option 2)
# find_package(glfw3 3.3 REQUIRED)

# add_subdirectory for anything containing a CMakeLists.txt file (option 1)
# EnTT
# add_subdirectory(${PGAPPORSTLNAME_SOURCE_DIR}/libraries/entt/)

# all cpp files (not included via CMakeLists.txt, option 2a)
file(GLOB PGAPPORSTLNAME_LIB_SOURCE_FILES LIST_DIRECTORIES false
    
    # note that this is not recursive, and will only add files/directories specified eg:
    # ${PGAPPORSTLNAME_SOURCE_DIR}/libraries/imgui/*.cpp
    # ${PGAPPORSTLNAME_SOURCE_DIR}/libraries/imgui/backends/imgui_impl_glfw.cpp
    # ${PGAPPORSTLNAME_SOURCE_DIR}/libraries/imgui/backends/imgui_impl_opengl3.cpp
)

# all header files (not included via CMakeLists.txt, option 2b)
file(GLOB_RECURSE PGAPPORSTLNAME_LIB_HEADER_FILES
    
    # eg:
    # ${PGAPPORSTLNAME_SOURCE_DIR}/libraries/imgui/*.h
)


# define links and frameworks for the above as libs
set(pgAppOrStlName_LINKED_LIBS 
    glfw
	glad
	glm
	CppUtils
    EnTT::EnTT
    # "-framework Cocoa" "-framework IOKit" "-framework CoreVideo" # frameworks for ImGui
)


# ==================================================================================================
#   Create and link generated executable
# ==================================================================================================

add_executable(pgAppOrStl 
               ${PGAPPORSTLNAME_SOURCE_FILES} 
               ${PGAPPORSTLNAME_HEADER_FILES}
               ${PGAPPORSTLNAME_LIB_SOURCE_FILES}
               ${PGAPPORSTLNAME_LIB_HEADER_FILES})

target_include_directories(pgAppOrStl PRIVATE ${pgAppOrStlName_INCLUDE_DIRS})
target_link_libraries(pgAppOrStl PRIVATE ${pgAppOrStlName_LINKED_LIBS})

target_compile_definitions(pgAppOrStl PRIVATE 
    $<$<CONFIG:Debug>:DEBUG_BUILD=1>
    $<$<CONFIG:Debug>:RELEASE_BUILD=0>
    $<$<CONFIG:Release>:DEBUG_BUILD=0>
    $<$<CONFIG:Release>:RELEASE_BUILD=1>
	
	# Add custom definitions:
	
	# folders
	# PROJECT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
	ASSETS_APP_SOURCE="${ASSETS_APP_SOURCE}"
	ASSETS_USER_SOURCE="${ASSETS_USER_SOURCE}"
	ASSETS_APP_DEST="${ASSETS_APP_DEST}"
	ASSETS_USER_DEST="${ASSETS_USER_DEST}"
	
	# booleans
	SYS_ASSET_STORAGE=$<BOOL:${USE_SYSTEM_APP_ASSET_STORAGE}>
	# MY_CUSTOM_BOOL=$<BOOL:${MY_CUSTOM_BOOL}>
)


# ==================================================================================================
#   Asset export configuration
# ==================================================================================================

if (USE_SYSTEM_APP_ASSET_STORAGE)
	message(STATUS "Using system asset folders for application data storage")
	
	if (EXPORT_SYSTEM_APP_ASSET_STORAGE)
		message(STATUS "Asset export enabled - will copy assets to system directories")
		
		# Create custom target for asset copying
		add_custom_target(copy_assets ALL
			COMMENT "Copying assets to system directories..."
			
			# Create destination directories (if they don't exist already)
			COMMAND ${CMAKE_COMMAND} -E make_directory "${ASSETS_APP_DEST}"
			COMMAND ${CMAKE_COMMAND} -E make_directory "${ASSETS_USER_DEST}"
			
			# Copy app assets
			COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${ASSETS_APP_SOURCE}" "${ASSETS_APP_DEST}"
			COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${ASSETS_USER_SOURCE}" "${ASSETS_USER_DEST}"
			
			# Only run if source directories exist
			COMMAND test -d "${ASSETS_APP_SOURCE}" || echo "Warning: ${ASSETS_APP_SOURCE} does not exist"
			COMMAND test -d "${ASSETS_USER_SOURCE}" || echo "Warning: ${ASSETS_USER_SOURCE} does not exist"
		)
		
		# Make sure assets are copied before building the main target
		add_dependencies(TestApp copy_assets)
		
	else()
		message(STATUS "Asset export disabled")
	endif()
else()
	message(STATUS "Using project asset folders for application data storage")
endif()


# ==================================================================================================
#   Platform-specific application bundle configuration
# ==================================================================================================

if(APPLE)
    # Create macOS .app bundle
    set_target_properties(pgAppOrStl PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.bunting.pgAppOrStl"
        MACOSX_BUNDLE_BUNDLE_NAME "pgAppOrStl"
        MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0"
        MACOSX_BUNDLE_COPYRIGHT "Copyright © 2025"
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Info.plist.in"
    )
    
    # Add app icon
    set(APP_ICON_MACOSX "${CMAKE_CURRENT_SOURCE_DIR}/assets/icon/icon.icns")
    set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    target_sources(pgAppOrStl PRIVATE ${APP_ICON_MACOSX})
	# To change app icon, use or modify the iconGen.sh script
    
elseif(WIN32) # TODO: test Windows .exe generation
    # Create Windows .exe with proper subsystem
    set_target_properties(pgAppOrStl PROPERTIES
        WIN32_EXECUTABLE TRUE
        # OUTPUT_NAME "pgAppOrStl"  # Optional: specify exact .exe name
    )
    
    # Add Windows resource file for icon/version info
    target_sources(pgAppOrStl PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/CMake/resources.rc")
    
endif()