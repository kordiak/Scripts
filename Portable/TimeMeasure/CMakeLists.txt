cmake_minimum_required(VERSION 2.8.11)
project(Hello)


set(HEADER_FILES TimeMeasure.hpp)

add_executable(Hello main.cpp ${HEADER_FILES})
