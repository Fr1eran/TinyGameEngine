aux_source_directory(. sources)
# file(GLOB sources CMAKE_CONFIGURE_DEPENDS *.cpp *.h)
# add_executable(main PUBLIC ${sources})

add_executable(Engine main.cpp
    Engine.h Engine.cpp
    EngineVisitor.h EngineVisitor.cpp
    EngineConfig.h EngineConfig.cpp
    Content/config.json
    Logger.h
    EngineContext.h EngineContext.cpp
    RandomManager.h RandomManager.cpp
    TimeManager.h TimeManager.cpp
    SaveManager.h SaveManager.cpp )
# add_library(Engine STATIC main.cpp)

# set compile option
target_compile_features(Engine PUBLIC cxx_std_20)

target_link_libraries(Engine
PUBLIC
    SFML::Graphics
    SFML::Window
    SFML::Audio
    SFML::System
PRIVATE
    nlohmann_json::nlohmann_json
    spdlog::spdlog
)

# set alias
# add_library(Engine::Engine ALIAS Engine)
