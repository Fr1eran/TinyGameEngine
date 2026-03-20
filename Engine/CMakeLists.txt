# aux_source_directory(. sources)
# file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)
# add_executable(main PUBLIC ${sources})

# Fetch library source code and build
include(FetchContent)
FetchContent_Declare(sfml URL https://github.com/SFML/SFML/archive/refs/tags/3.0.2.tar.gz)
FetchContent_Declare(json URL https://github.com/nlohmann/json/archive/refs/tags/v3.12.0.tar.gz)
FetchContent_Declare(logger URL https://github.com/gabime/spdlog/archive/refs/tags/v1.17.0.tar.gz)
FetchContent_Declare(tgui URL https://github.com/texus/TGUI/archive/refs/tags/v1.12.0.tar.gz)

set(SFML_BUILD_NETWORK OFF CACHE BOOL "Don't build SFML network module")
set(SPDLOG_USE_STD_FORMAT ON CACHE BOOL "Use std::format instead of fmt library")
set(TGUI_BACKEND SFML_GRAPHICS CACHE STRING "TGUI backend to use")
FetchContent_MakeAvailable(sfml json logger tgui)

file(GLOB_RECURSE sources "src/*.cpp")
add_executable(Engine ${sources})
# add_library(Engine STATIC ${sources})

# set include directories
target_include_directories(Engine PUBLIC include)

# set compile option
target_compile_features(Engine PUBLIC cxx_std_20)

target_link_libraries(Engine
PUBLIC
    SFML::Graphics
    SFML::Window
    SFML::Audio
    SFML::System
    TGUI::TGUI
PRIVATE
    nlohmann_json::nlohmann_json
    spdlog::spdlog
)

# set alias
# add_library(Engine::Engine ALIAS Engine)
