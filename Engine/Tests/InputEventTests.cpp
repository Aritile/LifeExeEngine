#include "Event/InputEvent.h"
#include "Event/InputEventFormat.h"

#include <gtest/gtest.h>
#include <format>

using namespace LifeExe;

TEST(InputEventTest, ShouldHoldExpectedAlternativeWhenAssigned)
{
    const EventData data = WindowResizeEventData{1920, 1080};

    EXPECT_TRUE(std::holds_alternative<WindowResizeEventData>(data));
    EXPECT_FALSE(std::holds_alternative<MouseMoveEventData>(data));
    EXPECT_EQ(std::get<WindowResizeEventData>(data).width, 1920);
}

TEST(InputEventTest, ShouldDefaultToMonostateWhenConstructedEmpty)
{
    const EventData data;

    EXPECT_TRUE(std::holds_alternative<std::monostate>(data));
}

TEST(InputEventTest, ShouldReturnNullWhenAccessingWrongAlternative)
{
    const EventData data = WindowResizeEventData{1920, 1080};

    EXPECT_EQ(std::get_if<MouseScrollEventData>(&data), nullptr);
}

TEST(InputEventTest, DefaultConstructedEventShouldBeInert)
{
    EXPECT_EQ(InputEvent{}.type(), EventType::None);
    EXPECT_EQ(KeyEventData{}.key, Key::None);
    EXPECT_EQ(KeyEventData{}.action, InputAction::Unknown);
    EXPECT_EQ(MouseButtonEventData{}.button, MouseButtonType::None);
    EXPECT_EQ(MouseButtonEventData{}.action, InputAction::Unknown);
}

TEST(InputEventTest, ShouldConvertEnumsToStringCorrectly)
{
    EXPECT_EQ(toString(Key::None), "None");
    EXPECT_EQ(toString(Key::Unknown), "Unknown");
    EXPECT_EQ(toString(Key::Esc), "Esc");
    EXPECT_EQ(toString(Key::Return), "Return");
    EXPECT_EQ(toString(Key::Tab), "Tab");
    EXPECT_EQ(toString(Key::Space), "Space");
    EXPECT_EQ(toString(Key::Backspace), "Backspace");
    EXPECT_EQ(toString(Key::Up), "Up");
    EXPECT_EQ(toString(Key::Down), "Down");
    EXPECT_EQ(toString(Key::Left), "Left");
    EXPECT_EQ(toString(Key::Right), "Right");
    EXPECT_EQ(toString(Key::Insert), "Insert");
    EXPECT_EQ(toString(Key::Delete), "Delete");
    EXPECT_EQ(toString(Key::Home), "Home");
    EXPECT_EQ(toString(Key::End), "End");
    EXPECT_EQ(toString(Key::PageUp), "PageUp");
    EXPECT_EQ(toString(Key::PageDown), "PageDown");
    EXPECT_EQ(toString(Key::Print), "Print");
    EXPECT_EQ(toString(Key::Pause), "Pause");
    EXPECT_EQ(toString(Key::Minus), "Minus");
    EXPECT_EQ(toString(Key::Equal), "Equal");
    EXPECT_EQ(toString(Key::LeftBracket), "LeftBracket");
    EXPECT_EQ(toString(Key::RightBracket), "RightBracket");
    EXPECT_EQ(toString(Key::Semicolon), "Semicolon");
    EXPECT_EQ(toString(Key::Quote), "Quote");
    EXPECT_EQ(toString(Key::Comma), "Comma");
    EXPECT_EQ(toString(Key::Period), "Period");
    EXPECT_EQ(toString(Key::Slash), "Slash");
    EXPECT_EQ(toString(Key::Backslash), "Backslash");
    EXPECT_EQ(toString(Key::Tilde), "Tilde");
    EXPECT_EQ(toString(Key::F1), "F1");
    EXPECT_EQ(toString(Key::F2), "F2");
    EXPECT_EQ(toString(Key::F3), "F3");
    EXPECT_EQ(toString(Key::F4), "F4");
    EXPECT_EQ(toString(Key::F5), "F5");
    EXPECT_EQ(toString(Key::F6), "F6");
    EXPECT_EQ(toString(Key::F7), "F7");
    EXPECT_EQ(toString(Key::F8), "F8");
    EXPECT_EQ(toString(Key::F9), "F9");
    EXPECT_EQ(toString(Key::F10), "F10");
    EXPECT_EQ(toString(Key::F11), "F11");
    EXPECT_EQ(toString(Key::F12), "F12");
    EXPECT_EQ(toString(Key::F13), "F13");
    EXPECT_EQ(toString(Key::F14), "F14");
    EXPECT_EQ(toString(Key::F15), "F15");
    EXPECT_EQ(toString(Key::F16), "F16");
    EXPECT_EQ(toString(Key::F17), "F17");
    EXPECT_EQ(toString(Key::F18), "F18");
    EXPECT_EQ(toString(Key::F19), "F19");
    EXPECT_EQ(toString(Key::F20), "F20");
    EXPECT_EQ(toString(Key::F21), "F21");
    EXPECT_EQ(toString(Key::F22), "F22");
    EXPECT_EQ(toString(Key::F23), "F23");
    EXPECT_EQ(toString(Key::F24), "F24");
    EXPECT_EQ(toString(Key::F25), "F25");
    EXPECT_EQ(toString(Key::NumPad0), "NumPad0");
    EXPECT_EQ(toString(Key::NumPad1), "NumPad1");
    EXPECT_EQ(toString(Key::NumPad2), "NumPad2");
    EXPECT_EQ(toString(Key::NumPad3), "NumPad3");
    EXPECT_EQ(toString(Key::NumPad4), "NumPad4");
    EXPECT_EQ(toString(Key::NumPad5), "NumPad5");
    EXPECT_EQ(toString(Key::NumPad6), "NumPad6");
    EXPECT_EQ(toString(Key::NumPad7), "NumPad7");
    EXPECT_EQ(toString(Key::NumPad8), "NumPad8");
    EXPECT_EQ(toString(Key::NumPad9), "NumPad9");
    EXPECT_EQ(toString(Key::NumPadDecimal), "NumPadDecimal");
    EXPECT_EQ(toString(Key::NumPadDivide), "NumPadDivide");
    EXPECT_EQ(toString(Key::NumPadMultiply), "NumPadMultiply");
    EXPECT_EQ(toString(Key::NumPadSubtract), "NumPadSubtract");
    EXPECT_EQ(toString(Key::NumPadAdd), "NumPadAdd");
    EXPECT_EQ(toString(Key::NumPadEnter), "NumPadEnter");
    EXPECT_EQ(toString(Key::NumPadEqual), "NumPadEqual");
    EXPECT_EQ(toString(Key::Key0), "Key0");
    EXPECT_EQ(toString(Key::Key1), "Key1");
    EXPECT_EQ(toString(Key::Key2), "Key2");
    EXPECT_EQ(toString(Key::Key3), "Key3");
    EXPECT_EQ(toString(Key::Key4), "Key4");
    EXPECT_EQ(toString(Key::Key5), "Key5");
    EXPECT_EQ(toString(Key::Key6), "Key6");
    EXPECT_EQ(toString(Key::Key7), "Key7");
    EXPECT_EQ(toString(Key::Key8), "Key8");
    EXPECT_EQ(toString(Key::Key9), "Key9");
    EXPECT_EQ(toString(Key::KeyA), "KeyA");
    EXPECT_EQ(toString(Key::KeyB), "KeyB");
    EXPECT_EQ(toString(Key::KeyC), "KeyC");
    EXPECT_EQ(toString(Key::KeyD), "KeyD");
    EXPECT_EQ(toString(Key::KeyE), "KeyE");
    EXPECT_EQ(toString(Key::KeyF), "KeyF");
    EXPECT_EQ(toString(Key::KeyG), "KeyG");
    EXPECT_EQ(toString(Key::KeyH), "KeyH");
    EXPECT_EQ(toString(Key::KeyI), "KeyI");
    EXPECT_EQ(toString(Key::KeyJ), "KeyJ");
    EXPECT_EQ(toString(Key::KeyK), "KeyK");
    EXPECT_EQ(toString(Key::KeyL), "KeyL");
    EXPECT_EQ(toString(Key::KeyM), "KeyM");
    EXPECT_EQ(toString(Key::KeyN), "KeyN");
    EXPECT_EQ(toString(Key::KeyO), "KeyO");
    EXPECT_EQ(toString(Key::KeyP), "KeyP");
    EXPECT_EQ(toString(Key::KeyQ), "KeyQ");
    EXPECT_EQ(toString(Key::KeyR), "KeyR");
    EXPECT_EQ(toString(Key::KeyS), "KeyS");
    EXPECT_EQ(toString(Key::KeyT), "KeyT");
    EXPECT_EQ(toString(Key::KeyU), "KeyU");
    EXPECT_EQ(toString(Key::KeyV), "KeyV");
    EXPECT_EQ(toString(Key::KeyW), "KeyW");
    EXPECT_EQ(toString(Key::KeyX), "KeyX");
    EXPECT_EQ(toString(Key::KeyY), "KeyY");
    EXPECT_EQ(toString(Key::KeyZ), "KeyZ");
    EXPECT_EQ(toString(Key::CapsLock), "CapsLock");
    EXPECT_EQ(toString(Key::ScrollLock), "ScrollLock");
    EXPECT_EQ(toString(Key::NumLock), "NumLock");
    EXPECT_EQ(toString(Key::LeftShift), "LeftShift");
    EXPECT_EQ(toString(Key::RightShift), "RightShift");
    EXPECT_EQ(toString(Key::LeftCtrl), "LeftCtrl");
    EXPECT_EQ(toString(Key::RightCtrl), "RightCtrl");
    EXPECT_EQ(toString(Key::LeftAlt), "LeftAlt");
    EXPECT_EQ(toString(Key::RightAlt), "RightAlt");
    EXPECT_EQ(toString(Key::LeftMeta), "LeftMeta");
    EXPECT_EQ(toString(Key::RightMeta), "RightMeta");
    EXPECT_EQ(toString(Key::Menu), "Menu");
    EXPECT_EQ(toString(Key::World1), "World1");
    EXPECT_EQ(toString(Key::World2), "World2");
    EXPECT_EQ(toString(Key::Count), "Unknown");

    EXPECT_EQ(toString(InputAction::Unknown), "Unknown");
    EXPECT_EQ(toString(InputAction::Release), "Release");
    EXPECT_EQ(toString(InputAction::Press), "Press");
    EXPECT_EQ(toString(InputAction::Repeat), "Repeat");

    EXPECT_EQ(toString(MouseButtonType::None), "None");
    EXPECT_EQ(toString(MouseButtonType::Left), "Left");
    EXPECT_EQ(toString(MouseButtonType::Middle), "Middle");
    EXPECT_EQ(toString(MouseButtonType::Right), "Right");
    EXPECT_EQ(toString(MouseButtonType::XButton1), "XButton1");
    EXPECT_EQ(toString(MouseButtonType::XButton2), "XButton2");
    EXPECT_EQ(toString(MouseButtonType::Button6), "Button6");
    EXPECT_EQ(toString(MouseButtonType::Button7), "Button7");
    EXPECT_EQ(toString(MouseButtonType::Button8), "Button8");

    EXPECT_EQ(toString(EventType::None), "None");
    EXPECT_EQ(toString(EventType::WindowClose), "WindowClose");
    EXPECT_EQ(toString(EventType::WindowResize), "WindowResize");
    EXPECT_EQ(toString(EventType::Key), "Key");
    EXPECT_EQ(toString(EventType::MouseButton), "MouseButton");
    EXPECT_EQ(toString(EventType::MouseMove), "MouseMove");
    EXPECT_EQ(toString(EventType::MouseScroll), "MouseScroll");
}

TEST(InputEventTest, ShouldFormatEnumsWithStdFormat)
{
    EXPECT_EQ(std::format("{}", Key::KeyA), "KeyA");
    EXPECT_EQ(std::format("{}", InputAction::Press), "Press");
    EXPECT_EQ(std::format("{}", MouseButtonType::Middle), "Middle");
    EXPECT_EQ(std::format("{}", EventType::None), "None");
    EXPECT_EQ(std::format("{}", EventType::WindowResize), "WindowResize");
}
