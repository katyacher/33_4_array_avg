cmake_minimum_required(VERSION 3.8.0)

add_executable(33_4_array_avg main.cpp ${MY_INCLUDE_DIR}/average.h )

target_include_directories(33_4_array_avg PUBLIC ${MY_INCLUDE_DIR})