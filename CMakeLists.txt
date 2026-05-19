cmake_minimum_required(VERSION 3.14)
project(SOLID_Patterns VERSION 1.0.0 LANGUAGES CXX)
set(CPACK_PACKAGE_NAME "solid-patterns")
set(CPACK_PACKAGE_NAME "solid-patterns")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
endif()

add_executable(solid_demo
    Patterns/SOLID/Program.cpp
    Patterns/SOLID/SRP.cpp
    Patterns/SOLID/LSP.cpp
    Patterns/SOLID/ISP.cpp
    Patterns/SOLID/DIP.cpp
)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

install(TARGETS solid_demo RUNTIME DESTINATION bin)
install(FILES
    Patterns/SOLID/SRP.cpp
    Patterns/SOLID/LSP.cpp
    Patterns/SOLID/ISP.cpp
    Patterns/SOLID/DIP.cpp
    DESTINATION share/solid_patterns/src
)
