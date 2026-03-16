#include <Engine/Managers/SaveManager.h>
#include <fstream>

SaveManager::SaveManager()
{
    if (std::ifstream file{"Content/Save.json"}) {
        m_values = nlohmann::json::parse(file);
    } else {
        m_values = nlohmann::json::object();
    }
}

bool SaveManager::Has(std::string_view key) const
{
    return m_values.contains(key);
}

void SaveManager::Erase(std::string_view key)
{
    m_values.erase(key);
}

void SaveManager::Clear()
{
    m_values.clear();
}

SaveManager::~SaveManager() {
    if(!m_values.empty())
    {
        if(std::ofstream file {"Content/Save.json"})
        {
            file << m_values.dump(4);
        }
    }
}
