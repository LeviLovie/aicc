cmake_minimum_required(VERSION 3.8.0)
project(aicc VERSION 0.0.1 LANGUAGES C CXX)
enable_testing()

file(GLOB BOARD_SRC src/board/*.cpp)
add_library(board ${BOARD_SRC})

# Executable
add_executable(aicc src/main.cpp)
target_link_libraries(aicc board)

# Tests
include(FetchContent)
FetchContent_Declare(googletest GIT_REPOSITORY https://github.com/google/googletest GIT_TAG v1.14.0)
FetchContent_MakeAvailable(googletest)
file(GLOB TESTS tests/*.cpp)
add_executable(tests ${TESTS})
target_link_libraries(tests board gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)