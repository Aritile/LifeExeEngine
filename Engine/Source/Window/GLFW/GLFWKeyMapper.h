#pragma once

#include "Event/InputEvent.h"
#include "Core/Types.h"

namespace LifeExe::GLFWKeyMapper
{
[[nodiscard]] Key toKey(int glfwKey) noexcept;
[[nodiscard]] MouseButtonType toMouseButton(int glfwButton) noexcept;
[[nodiscard]] InputAction toAction(int glfwAction) noexcept;
}  // namespace LifeExe::GLFWKeyMapper
