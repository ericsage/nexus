cmake_minimum_required(VERSION 3.2.2)
project(nexus)

find_package(Protobuf REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cc")

set(CMAKE_CXX_STANDARD 11)

link_libraries(grpc++_unsecure grpc gpr ${PROTOBUF_LIBRARY})

add_executable(nexus ${SOURCES})`
