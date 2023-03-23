cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(FINALPROJECT)
set(CMAKE_CXX_STANDARD 17)

file(GLOB
        INC
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
        )

file(
        GLOB
        SRC
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_executable(csi140 ${SRC} ${INC} main.cpp)