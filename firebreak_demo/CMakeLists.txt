cmake_minimum_required (VERSION 3.8)

add_executable (firebreak_demo "firebreak_demo.cpp")
target_link_libraries(firebreak_demo sharks::firebreak)
