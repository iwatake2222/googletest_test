cmake_minimum_required(VERSION 3.10)

# Create project
set(ProjectName "main")
project(${ProjectName})

# Compile option
set(CMAKE_INSTALL_PREFIX "./install" CACHE STRING "install path" FORCE)
include(${CMAKE_SOURCE_DIR}/cmakes/compile_option.cmake)

# Create executable file
add_executable(${ProjectName})

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
