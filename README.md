# Sample project for GoogleTest
- Create a simple calculator with GoogleTest
- Continuous Integration with GitHub Actions

## CI Status
Status | Build Type
------ | ----------
[![CMake_x64](https://github.com/iwatake2222/googletest_test/actions/workflows/cmake_x64.yml/badge.svg)](https://github.com/iwatake2222/googletest_test/actions/workflows/cmake_x64.yml) | windows-latest, ubuntu-latest, macos-latest
[![CMake_ARM](https://github.com/iwatake2222/googletest_test/actions/workflows/cmake_arm.yml/badge.svg)](https://github.com/iwatake2222/googletest_test/actions/workflows/cmake_arm.yml) | armv7 + ubuntu18.04, aarch64 + ubuntu18.04
[![CodeQL](https://github.com/iwatake2222/googletest_test/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/iwatake2222/googletest_test/actions/workflows/codeql-analysis.yml) | ubuntu-latest

## Class Diagram
### For product
- To test core logic and input/output, make `Arithmetic` and `Prompt` module, respectively
- `Calculator` module contains these modules
- However, `Calculator` module doesn't create these modules. Instead, use dependency injection
    - It's better to have a factory module, but in this project main function creates these modules to make it easy
- So that, I can use mock modules when running unit test for `Calculator` module

![](00_doc/class_diagram.jpg)

### For calculator unit test
![](00_doc/test_class_diagram.jpg)

## Structure
- main.cpp
- calculator/
- arithmetic/
- prompt/
- test/
    - calculator/
    - arithmetic/
    - prompt/

## How to
### Linux
```sh
mkdir -p build && cd build
cmake ..
make
ctest
./main
`>+ 1 2`
```

### Visual Studio
- Create Visual Studio project using cmake-gui
- Build the project
- Normal execution
    - Set `main` as a startup project
    - Run
    - `>+ 1 2`
- Test
    - Open Test Explorer
    - Run All Tests

![](00_doc/test_in_vs.jpg)

