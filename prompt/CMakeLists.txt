cmake_minimum_required(VERSION 3.10)

set(LibraryName Prompt)

# Create library
add_library(${LibraryName}
    i_prompt.h prompt.h prompt.cpp
)

target_include_directories(${LibraryName} PUBLIC ./)    # add public so that test module can include header files
