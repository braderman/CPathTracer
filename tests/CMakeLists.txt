cmake_minimum_required(VERSION 3.10)

project(path_tracer_tests)

include_directories(../googletest-1.8.0/googletest/include)

add_executable(path_tracer_tests
	../vec3.c
	../ray.c
	../googletest-1.8.0/googletest/src/gtest_main.cc
	vec3_tests.cpp
	ray_tests.cpp
)

target_link_libraries(path_tracer_tests gtest)

