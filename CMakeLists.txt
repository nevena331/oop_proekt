cmake_minimum_required(VERSION 3.10)
project(HikingManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/SleepingPlace.cpp
    src/Hut.cpp
    src/Camping.cpp
    src/Room.cpp
    src/main.cpp
)

# Create executable
add_executable(hiking_system ${SOURCES})

# Set output directory
set_target_properties(hiking_system PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
)
