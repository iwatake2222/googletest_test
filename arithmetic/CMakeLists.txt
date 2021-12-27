cmake_minimum_required(VERSION 3.10)

set(LibraryName Arithmetic)

# Create library
add_library(${LibraryName}
    i_arithmetic.h arithmetic.h arithmetic.cpp
)

target_include_directories(${LibraryName} PUBLIC ./)    # add public so that test module can include header files
