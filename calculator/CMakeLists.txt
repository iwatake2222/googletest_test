cmake_minimum_required(VERSION 3.14)

set(LibraryName Calculator)

# Create library
add_library(${LibraryName})

# Add source
target_sources(${LibraryName} PRIVATE 
    Calculator.h Calculator.cpp
)
target_include_directories(${LibraryName} PUBLIC ./)    # add public so that test module can include header files

# Add sub modules
target_link_libraries(${LibraryName} Arithmetic)
target_link_libraries(${LibraryName} Prompt)
