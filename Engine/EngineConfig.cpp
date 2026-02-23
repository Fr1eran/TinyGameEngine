#include "EngineConfig.h"
#include <fstream>
#include <nlohmann/json.hpp>

EngineConfig::EngineConfig()
{
    std::ifstream file("Content/config.json");
    assert(file);

    nlohmann::json json = nlohmann::json::parse(file);
    windowTitle = json["windowTitle"];
    windowSize = {json["windowSize"][0], json["windowSize"][1]};
    maximumDeltaTime = sf::seconds(json["maximumDeltaTime"]);
}
