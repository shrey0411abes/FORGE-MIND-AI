cmake_minimum_required(VERSION 3.20)

project(
    FORGE_MIND_AI
    VERSION 1.0.0
    DESCRIPTION "AI Powered Interview Preparation Platform"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    FORGE_MIND_AI

    src/main.cpp

    src/core/Application.cpp
    src/utils/Logger.cpp
)

target_include_directories(
    FORGE_MIND_AI

    PRIVATE

    include
)