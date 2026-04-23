cmake_minimum_required(VERSION 3.20)
project(peeCXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Required for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(pee
    src/main.cpp
)

target_include_directories(pee PRIVATE include)
target_link_libraries(pee PRIVATE Qt6::Core Qt6::Widgets)