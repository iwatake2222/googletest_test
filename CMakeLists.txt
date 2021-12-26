cmake_minimum_required(VERSION 3.14)

# Create project
set(ProjectName "main")
project(${ProjectName})

# Create executable file
add_executable(${ProjectName})

# Compile option
set(CMAKE_INSTALL_PREFIX "./install" CACHE STRING "install path" FORCE)
if(NOT MSVC)
    set(CMAKE_C_FLAGS "-Wall")
    set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_C_FLAGS_DEBUG "-g3 -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++14")
    set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
    set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
    if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        message(STATUS "No build type selected, default to Release")
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type (default Debug)" FORCE)
    endif()
endif()

# Add source
target_sources(${ProjectName} PRIVATE 
    main.cpp
)

# Add sub modules
add_subdirectory(./arithmetic)
add_subdirectory(./prompt)
add_subdirectory(./calculator)
target_link_libraries(${ProjectName} Calculator)
target_link_libraries(${ProjectName} Arithmetic)
target_link_libraries(${ProjectName} Prompt)

# Add test module
enable_testing()
add_subdirectory(./test)
