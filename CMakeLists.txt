cmake_minimum_required(VERSION 3.8.0)
project(33_4_array_avg VERSION 0.1.0 LANGUAGES C CXX)

add_executable(33_4_array_avg main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
