cmake_minimum_required(VERSION 3.10)

project(project_name
   VERSION 0.0.1
   DESCRIPTION "project_name description"
   LANGUAGES CXX
)

# Include cmake scripts
include(cmake/configurations.cmake)
include(cmake/warnings.cmake)
include(cmake/conan.cmake)

# Project settings
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Settings I might want to change
set(BUILDING_ON_OPENSUSE OFF CACHE BOOL "Building on openSUSE is slightly different")

# Set up Conan dependencies
# To find packages:
#    - https://bintray.com/bincrafters/public-conan
#    - https://conan.io/center/
set(CONAN_EXTRA_REQUIRES "")
set(CONAN_EXTRA_OPTIONS "")
set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES} 
   gtest/1.10.0
   )
# Only import conan packages for the following libraries if on Windows or Debian, while linking against
# system installed packages on openSUSE.
if(NOT BUILDING_ON_OPENSUSE)
   set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES}
       qt/5.15.2@bincrafters/stable
)
endif()
run_conan()

# Set output directory of all projects to be somewhere sensible
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Projects in this solution
add_subdirectory(library)
add_subdirectory(tests)
add_subdirectory(executable)

# Group CMake projects together
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Make app the default startup project in Visual Studio rather than autogenerated ALL_BUILDS project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT executable)

# Set working directory property in Visual Studio so that resource files will be in expected relative place
set_property(TARGET executable PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
