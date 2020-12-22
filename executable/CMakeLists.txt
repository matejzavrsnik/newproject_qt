cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(executable
   VERSION 0.0.1
   DESCRIPTION "the app itself"
   LANGUAGES CXX
)

# Add these files to this binary
file(GLOB HeaderFiles *.h)
file(GLOB SourceFiles *.cpp)

set(SOURCES ${HeaderFiles} ${SourceFiles})

# The result
add_executable(executable ${SOURCES})

# set compiler warnings as defined in cmake/warnings and included in root CMakeLists.txt
set_project_warnings(executable)

# Link with libraries
target_link_libraries(executable 
   library # exists in this solution, imported in CMakeLists.txt
)
