cmake_minimum_required(VERSION 3.29)
project(RSA)

set(CMAKE_CXX_STANDARD 20)


add_executable(RSA main.cpp rsa.cpp rsa.h)


find_package(Boost REQUIRED)

target_link_libraries(RSA Boost::boost)