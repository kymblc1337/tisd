cmake_minimum_required(VERSION 3.15)
project(lab_05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_05
        lab_05_tisd.cpp
        list.h
        queue_v.h)
