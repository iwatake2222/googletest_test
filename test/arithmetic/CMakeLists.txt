cmake_minimum_required(VERSION 3.14)

set(TestName TestArithmetic)

# Create test
add_executable(${TestName}
    test_arithmetic.cpp
)

# Link to gtest_main to call test cases
target_link_libraries(${TestName} gtest_main)
gtest_discover_tests(${TestName})

# Link to the target module
target_link_libraries(${TestName} Arithmetic)
