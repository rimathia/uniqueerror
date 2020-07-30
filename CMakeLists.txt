cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(uniqueerror
        VERSION 0.1
        DESCRIPTION "example for ensuring global uniqueness of error numbers"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(registry)
add_subdirectory(checked_division)
add_subdirectory(fmt)

add_executable(main main.cpp)
target_link_libraries(main registry checked_division)
