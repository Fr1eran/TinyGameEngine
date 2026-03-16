# aux_source_directory(. sources)
# file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)
# add_executable(main PUBLIC ${sources})

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
