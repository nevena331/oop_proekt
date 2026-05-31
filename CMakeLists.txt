cmake_minimum_required(VERSION 3.10)
project(HikingManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files (shared between main and tests)
set(CORE_SOURCES
    src/SleepingPlace.cpp
    src/Hut.cpp
    src/Camping.cpp
    src/Room.cpp
    src/Tourist.cpp
    src/Trail.cpp
    src/HikingGroup.cpp
    src/Booking.cpp
)

# Create test executable
add_executable(test_suite ${CORE_SOURCES} src/tests.cpp)

# Set output directories
set_target_properties(test_suite PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
)

# Enable testing
enable_testing()
add_test(NAME AllTests COMMAND test_suite WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
