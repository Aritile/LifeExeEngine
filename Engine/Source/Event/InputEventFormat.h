#pragma once

#include "Event/InputEvent.h"
#include <format>
#include <string_view>

template <>
struct std::formatter<LifeExe::Key> : std::formatter<std::string_view>
{
    auto format(LifeExe::Key key, std::format_context& ctx) const
    {
        return std::formatter<std::string_view>::format(LifeExe::toString(key), ctx);
    }
};

template <>
struct std::formatter<LifeExe::InputAction> : std::formatter<std::string_view>
{
    auto format(LifeExe::InputAction action, std::format_context& ctx) const
    {
        return std::formatter<std::string_view>::format(LifeExe::toString(action), ctx);
    }
};

template <>
struct std::formatter<LifeExe::MouseButtonType> : std::formatter<std::string_view>
{
    auto format(LifeExe::MouseButtonType button, std::format_context& ctx) const
    {
        return std::formatter<std::string_view>::format(LifeExe::toString(button), ctx);
    }
};

template <>
struct std::formatter<LifeExe::EventType> : std::formatter<std::string_view>
{
    auto format(LifeExe::EventType type, std::format_context& ctx) const
    {
        return std::formatter<std::string_view>::format(LifeExe::toString(type), ctx);
    }
};