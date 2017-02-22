cmake_minimum_required(VERSION 3.6.2)
project(nexus)

include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(nexus ${SOURCES})
