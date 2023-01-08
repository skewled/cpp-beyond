cmake_minimum_required(VERSION 3.18.4)

# Do we want to build tests
option(BUILD_TESTING "Test app library features." ON)
option(BUILD_EXAMPLES "Try example app." OFF)

# Project will use C/CPP
project(app C CXX)  # since app is a subproject already - no executable is built for this

# Set C Standards, might need to update to 17 later...
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Organize applications, libraries, etc. in folders in the IDE.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Ensure proper loading of side-loaded shared libraries
# on all targets.
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

if(APPLE)
    set(CMAKE_INSTALL_RPATH "@loader_path")
elseif(UNIX)
    set(CMAKE_INSTALL_RPATH "\$ORIGIN")
endif()

# Google Test
set(BUILD_GTEST ON CACHE BOOL "Builds the googletest subproject" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "Builds the googlemock subproject" FORCE)
add_subdirectory(googletest)
set_target_properties(gtest gtest_main PROPERTIES
    FOLDER Libraries
)

# Add subdirectories directly in this repository.
add_subdirectory(app)

if (BUILD_TESTING)
  add_subdirectory(test)
endif()


# Don't add the goofy "d" postfix for debug builds of libraries.
if (BUILD_EXAMPLES) 
  add_subdirectory(example)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})