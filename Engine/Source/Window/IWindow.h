#pragma once

#include <string>
#include <functional>
#include <cstdint>

#include "Event/Event.h"
#include "Event/InputEvent.h"
#include "Core/Types.h"

namespace LifeExe
{

struct WindowSettings
{
    std::string title{};
    int width{800};
    int height{600};
    int x{50};
    int y{50};
};

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void setTitle(const std::string& title) = 0;
    virtual bool isValid() const = 0;
    virtual bool shouldClose() const = 0;
    virtual Event<const InputEvent&>& windowEvent() = 0;
};

}  // namespace LifeExe
