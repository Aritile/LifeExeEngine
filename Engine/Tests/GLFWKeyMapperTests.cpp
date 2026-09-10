#include "Window/GLFW/GLFWKeyMapper.h"
#include <gtest/gtest.h>
#include <GLFW/glfw3.h>
#include <unordered_set>

using namespace LifeExe;

TEST(GLFWKeyMapperTest, ShouldMapKeysCorrectly)
{
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_ESCAPE), Key::Esc);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_ENTER), Key::Return);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_TAB), Key::Tab);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_BACKSPACE), Key::Backspace);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_SPACE), Key::Space);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_INSERT), Key::Insert);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_DELETE), Key::Delete);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_UP), Key::Up);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_DOWN), Key::Down);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_LEFT), Key::Left);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_RIGHT), Key::Right);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_PAGE_UP), Key::PageUp);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_PAGE_DOWN), Key::PageDown);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_HOME), Key::Home);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_END), Key::End);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_PRINT_SCREEN), Key::Print);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_PAUSE), Key::Pause);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_EQUAL), Key::Equal);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_MINUS), Key::Minus);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_LEFT_BRACKET), Key::LeftBracket);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_RIGHT_BRACKET), Key::RightBracket);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_SEMICOLON), Key::Semicolon);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_APOSTROPHE), Key::Quote);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_GRAVE_ACCENT), Key::Tilde);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_BACKSLASH), Key::Backslash);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_COMMA), Key::Comma);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_PERIOD), Key::Period);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_SLASH), Key::Slash);

    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F1), Key::F1);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F2), Key::F2);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F3), Key::F3);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F4), Key::F4);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F5), Key::F5);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F6), Key::F6);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F7), Key::F7);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F8), Key::F8);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F9), Key::F9);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F10), Key::F10);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F11), Key::F11);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F12), Key::F12);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F13), Key::F13);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F14), Key::F14);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F15), Key::F15);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F16), Key::F16);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F17), Key::F17);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F18), Key::F18);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F19), Key::F19);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F20), Key::F20);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F21), Key::F21);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F22), Key::F22);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F23), Key::F23);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F24), Key::F24);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F25), Key::F25);

    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_0), Key::NumPad0);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_1), Key::NumPad1);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_2), Key::NumPad2);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_3), Key::NumPad3);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_4), Key::NumPad4);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_5), Key::NumPad5);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_6), Key::NumPad6);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_7), Key::NumPad7);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_8), Key::NumPad8);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_9), Key::NumPad9);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_DECIMAL), Key::NumPadDecimal);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_DIVIDE), Key::NumPadDivide);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_MULTIPLY), Key::NumPadMultiply);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_SUBTRACT), Key::NumPadSubtract);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_ADD), Key::NumPadAdd);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_ENTER), Key::NumPadEnter);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_KP_EQUAL), Key::NumPadEqual);

    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_0), Key::Key0);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_1), Key::Key1);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_2), Key::Key2);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_3), Key::Key3);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_4), Key::Key4);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_5), Key::Key5);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_6), Key::Key6);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_7), Key::Key7);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_8), Key::Key8);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_9), Key::Key9);

    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_A), Key::KeyA);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_B), Key::KeyB);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_C), Key::KeyC);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_D), Key::KeyD);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_E), Key::KeyE);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_F), Key::KeyF);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_G), Key::KeyG);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_H), Key::KeyH);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_I), Key::KeyI);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_J), Key::KeyJ);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_K), Key::KeyK);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_L), Key::KeyL);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_M), Key::KeyM);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_N), Key::KeyN);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_O), Key::KeyO);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_P), Key::KeyP);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_Q), Key::KeyQ);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_R), Key::KeyR);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_S), Key::KeyS);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_T), Key::KeyT);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_U), Key::KeyU);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_V), Key::KeyV);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_W), Key::KeyW);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_X), Key::KeyX);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_Y), Key::KeyY);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_Z), Key::KeyZ);

    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_CAPS_LOCK), Key::CapsLock);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_SCROLL_LOCK), Key::ScrollLock);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_NUM_LOCK), Key::NumLock);

    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_LEFT_SHIFT), Key::LeftShift);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_RIGHT_SHIFT), Key::RightShift);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_LEFT_CONTROL), Key::LeftCtrl);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_RIGHT_CONTROL), Key::RightCtrl);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_LEFT_ALT), Key::LeftAlt);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_RIGHT_ALT), Key::RightAlt);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_LEFT_SUPER), Key::LeftMeta);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_RIGHT_SUPER), Key::RightMeta);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_MENU), Key::Menu);

    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_WORLD_1), Key::World1);
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_WORLD_2), Key::World2);
}

TEST(GLFWKeyMapperTest, ShouldReturnUnknownForUnknownKey)
{
    EXPECT_EQ(GLFWKeyMapper::toKey(GLFW_KEY_UNKNOWN), Key::Unknown);
    EXPECT_EQ(GLFWKeyMapper::toKey(-1), Key::Unknown);
    EXPECT_EQ(GLFWKeyMapper::toKey(9999), Key::Unknown);
}

TEST(GLFWKeyMapperTest, ShouldMapMouseButtonsCorrectly)
{
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_LEFT), MouseButtonType::Left);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_RIGHT), MouseButtonType::Right);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_MIDDLE), MouseButtonType::Middle);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_4), MouseButtonType::XButton1);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_5), MouseButtonType::XButton2);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_6), MouseButtonType::Button6);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_7), MouseButtonType::Button7);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(GLFW_MOUSE_BUTTON_8), MouseButtonType::Button8);
}

TEST(GLFWKeyMapperTest, ShouldReturnNoneForUnknownMouseButton)
{
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(-1), MouseButtonType::None);
    EXPECT_EQ(GLFWKeyMapper::toMouseButton(9999), MouseButtonType::None);
}

TEST(GLFWKeyMapperTest, ShouldMapActionsCorrectly)
{
    EXPECT_EQ(GLFWKeyMapper::toAction(GLFW_PRESS), InputAction::Press);
    EXPECT_EQ(GLFWKeyMapper::toAction(GLFW_RELEASE), InputAction::Release);
    EXPECT_EQ(GLFWKeyMapper::toAction(GLFW_REPEAT), InputAction::Repeat);
}

TEST(GLFWKeyMapperTest, ShouldReturnUnknownForUnknownAction)
{
    EXPECT_EQ(GLFWKeyMapper::toAction(-1), InputAction::Unknown);
    EXPECT_EQ(GLFWKeyMapper::toAction(9999), InputAction::Unknown);
}

TEST(GLFWKeyMapperTest, AllKeysUpToCountShouldHaveKnownStringRepresentation)
{
    std::unordered_set<std::string_view> seenNames;
    for (uint16 i = 0; i < std::to_underlying(Key::Count); ++i)
    {
        const auto key = static_cast<Key>(i);
        const auto name = toString(key);
        if (key == Key::Unknown)
        {
            EXPECT_EQ(name, "Unknown");
        }
        else
        {
            EXPECT_NE(name, "Unknown") << "Key value " << i << " has Unknown string representation";
            EXPECT_FALSE(name.empty()) << "Key value " << i << " has empty string representation";
        }
        EXPECT_TRUE(seenNames.insert(name).second) << "Duplicate key name: " << name;
    }
}

TEST(GLFWKeyMapperTest, AllMappedGLFWKeysShouldBeDistinct)
{
    std::unordered_set<Key> seenKeys;
    for (int glfwKey = GLFW_KEY_SPACE; glfwKey <= GLFW_KEY_LAST; ++glfwKey)
    {
        const Key key = GLFWKeyMapper::toKey(glfwKey);
        if (key != Key::Unknown)
        {
            EXPECT_NE(key, Key::None);
            const bool inserted = seenKeys.insert(key).second;
            EXPECT_TRUE(inserted) << "Duplicate mapping for key " << toString(key) << " from GLFW key " << glfwKey;
        }
    }
    // Every Key must be reachable from GLFW, except None and Unknown which are not real keys
    EXPECT_EQ(seenKeys.size(), static_cast<size_t>(std::to_underlying(Key::Count)) - 2);
}

TEST(GLFWKeyMapperTest, AllMappedGLFWMouseButtonsShouldBeDistinct)
{
    std::unordered_set<MouseButtonType> seenButtons;
    for (int glfwButton = GLFW_MOUSE_BUTTON_1; glfwButton <= GLFW_MOUSE_BUTTON_LAST; ++glfwButton)
    {
        const MouseButtonType button = GLFWKeyMapper::toMouseButton(glfwButton);
        EXPECT_NE(button, MouseButtonType::None);
        const bool inserted = seenButtons.insert(button).second;
        EXPECT_TRUE(inserted) << "Duplicate mapping for mouse button " << toString(button) << " from GLFW button " << glfwButton;
    }
    // Every GLFW mouse button must map to a distinct MouseButtonType
    EXPECT_EQ(seenButtons.size(), static_cast<size_t>(GLFW_MOUSE_BUTTON_LAST) + 1);
}
