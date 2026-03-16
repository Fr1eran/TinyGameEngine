#include "Engine/Utils/InputBinding.h"
#include <SFML/Window/Joystick.hpp>
#include <array>
#include <optional>

namespace Mapping
{
const std::array<int, 12> PlayStation = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const std::array<int, 12> Xbox = {2, 0, 1, 3, 4, 5, -1, -1, 6, 7, 8, 9};
const int SonyVID = 0x054C;
const int MicrosoftVID = 0x045E;

auto const& GetMapping(int id)
{
    const int vendorId = sf::Joystick::getIdentification(id).vendorId;

    return (vendorId == MicrosoftVID) ? Xbox : PlayStation;
}

} // namespace Mapping

std::optional<int> Input::LogicalToHardware(GamepadButton button, int id)
{
    auto const& mapping = Mapping::GetMapping(id);
    const int value = mapping[(int)button];

    return (value != -1) ? std::optional<int>(value) : std::nullopt;
}

std::optional<GamepadButton> Input::HardwareToLogical(int button, int id)
{
    auto const& mapping = Mapping::GetMapping(id);
    for (std::size_t i = 0; i < mapping.size(); ++i)
    {
        if (button == mapping[i])
        {
            return GamepadButton(i);
        }
    }
    return std::nullopt;
}