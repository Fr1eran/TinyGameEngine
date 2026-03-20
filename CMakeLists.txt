cmake_minimum_required(VERSION 3.28)

project(TinyGameEngine
    VERSION 0.0.1
    DESCRIPTION "A game engine built with SFML"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# build option
option(BUILD_ENGINE "Build the game engine" ON)
option(BUILD_GAMES "Build example games" OFF)

# add subproject
if(BUILD_ENGINE)
    add_subdirectory(Engine)
endif()

if(BUILD_GAMES)
    add_subdirectory(Games)
endif()
