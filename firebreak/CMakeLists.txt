cmake_minimum_required (VERSION 3.8)


ADD_LIBRARY(firebreak "firebreak.cpp" "firebreak.cpp")
target_include_directories(firebreak INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_compile_features(firebreak PUBLIC cxx_std_11)
add_library(sharks::firebreak ALIAS firebreak)
