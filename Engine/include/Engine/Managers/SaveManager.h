#pragma once
#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <nlohmann/json.hpp>
#include <string_view>

class SaveManager
{
private:
    nlohmann::json m_values;

public:
    SaveManager();
    ~SaveManager();

    void Set(std::string_view key, auto value) { m_values[key] = value; }

    auto Get(std::string_view key, auto defaultValue = {}) const
    {
        return m_values.value(key, defaultValue);
    }

    bool Has(std::string_view key) const;
    void Erase(std::string_view key);
    void Clear();
};

#endif // SAVEMANAGER_H
