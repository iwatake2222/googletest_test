cmake_minimum_required(VERSION 3.14)

set(LibraryName Prompt)

# Create library
add_library(${LibraryName})

# Add source
target_sources(${LibraryName} PRIVATE 
    i_prompt.h prompt.h prompt.cpp
)
target_include_directories(${LibraryName} PUBLIC ./)    # add public so that test module can include header files
