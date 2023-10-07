cmake_minimum_required(VERSION 3.0.0)
project(prefixSearch VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

FILE(GLOB SRCS "src/*.cpp" "src/*/*.cpp")

add_executable(prefixSearch ${SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
