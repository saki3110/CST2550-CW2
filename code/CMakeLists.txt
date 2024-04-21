# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Project name
project(VideoRentalSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add include directories
include_directories(include)

# Add Catch2 library
add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE "C:/Users/Shika/Downloads/Catch2-devel/Catch2-devel/src/catch2")

# Add your source files here
set(SOURCES
    src/main.cpp
    src/Rental.cpp
    src/Movie.cpp
    src/Customer.cpp
)

# Add your test files here
set(TEST_SOURCES
    test/test.cpp
)

# Add executable for main program
add_executable(VideoRental ${SOURCES})

# Add executable for tests
add_executable(TestRunner ${TEST_SOURCES})

# Link Catch2 library to tests
target_link_libraries(TestRunner Catch2)

# Add a custom target to run tests
add_custom_target(run_tests COMMAND TestRunner DEPENDS TestRunner)
