cmake_minimum_required(VERSION 3.0.0)
project(aicc VERSION 0.0.1 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB SRC src/*.cpp)
add_executable(aicc ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
