#pragma once

#include "Core/Types.h"

namespace LifeExe
{

struct WindowId
{
    uint32 value{0};
    constexpr explicit WindowId(uint32 id = 0) : value(id) {}

    constexpr WindowId operator++(int)
    {
        WindowId temp = *this;
        ++value;
        return temp;
    }

    constexpr auto operator<=>(const WindowId&) const = default;
};
}  // namespace LifeExe

namespace std
{
template <>
struct hash<LifeExe::WindowId>
{
    size_t operator()(const LifeExe::WindowId& id) const noexcept  //
    {
        return std::hash<LifeExe::uint32>{}(id.value);
    }
};
}  // namespace std
