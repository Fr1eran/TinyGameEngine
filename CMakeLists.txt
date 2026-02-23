cmake_minimum_required(VERSION 3.25)

project(TinyGameEngine
    VERSION 0.0.1
    DESCRIPTION "A game engine built with SFML"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# build option
option(BUILD_ENGINE "Build the game engine" ON)
option(BUILD_GAMES "Build example games" OFF)

# find build dependence
find_package(SFML COMPONENTS Graphics Window Audio System REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# add subproject
if(BUILD_ENGINE)
    add_subdirectory(Engine)
endif()

if(BUILD_GAMES)
    add_subdirectory(Games)
endif()
