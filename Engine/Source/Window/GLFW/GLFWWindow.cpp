#include "GLFWWindow.h"
#include "Window/GLFW/GLFWKeyMapper.h"
#include "Log/Log.h"
#include <GLFW/glfw3.h>

using namespace LifeExe;

DEFINE_LOG_CATEGORY_STATIC(LogGLFWWindow);

GLFWWindow::GLFWWindow(WindowId id, const WindowSettings& settings)  //
    : m_id(id)
{
    // init ->
    m_window = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);
    if (!m_window)
    {
        LE_LOG(LogGLFWWindow, Error, "Failed to create GLFW window!");
        return;
    }
    glfwSetWindowPos(m_window, settings.x, settings.y);

    // user pointer ->
    glfwSetWindowUserPointer(m_window, this);

    // events ->
    glfwSetWindowCloseCallback(m_window,
        [](GLFWwindow* window)
        {
            auto* thisWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
            if (!thisWindow) return;

            InputEvent event;
            event.windowId = thisWindow->m_id;
            event.data = WindowCloseEventData{};
            thisWindow->m_windowEvent.invoke(event);
        });

    glfwSetFramebufferSizeCallback(m_window,
        [](GLFWwindow* window, int width, int height)
        {
            auto* thisWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
            if (!thisWindow) return;

            InputEvent event;
            event.windowId = thisWindow->m_id;
            event.data = WindowResizeEventData{width, height};
            thisWindow->m_windowEvent.invoke(event);
        });

    glfwSetKeyCallback(m_window,
        [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            auto* thisWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
            if (!thisWindow) return;

            InputEvent event;
            event.windowId = thisWindow->m_id;
            event.data = KeyEventData{                      //
                .key = GLFWKeyMapper::toKey(key),           //
                .action = GLFWKeyMapper::toAction(action),  //
                .scancode = scancode};
            thisWindow->m_windowEvent.invoke(event);
        });

    glfwSetCursorPosCallback(m_window,
        [](GLFWwindow* window, double xpos, double ypos)
        {
            auto* thisWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
            if (!thisWindow) return;

            InputEvent event;
            event.windowId = thisWindow->m_id;
            event.data = MouseMoveEventData{xpos, ypos};
            thisWindow->m_windowEvent.invoke(event);
        });

    glfwSetMouseButtonCallback(m_window,
        [](GLFWwindow* window, int button, int action, int mods)
        {
            auto* thisWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
            if (!thisWindow) return;

            InputEvent event;
            event.windowId = thisWindow->m_id;
            event.data = MouseButtonEventData{
                .button = GLFWKeyMapper::toMouseButton(button),  //
                .action = GLFWKeyMapper::toAction(action),       //
            };
            thisWindow->m_windowEvent.invoke(event);
        });

    glfwSetScrollCallback(m_window,
        [](GLFWwindow* window, double xoffset, double yoffset)
        {
            auto* thisWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
            if (!thisWindow) return;

            InputEvent event;
            event.windowId = thisWindow->m_id;
            event.data = MouseScrollEventData{xoffset, yoffset};
            thisWindow->m_windowEvent.invoke(event);
        });
}

GLFWWindow::~GLFWWindow()
{
    if (m_window)
    {
        glfwSetWindowUserPointer(m_window, nullptr);
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
}

void GLFWWindow::setTitle(const std::string& title)
{
    if (!m_window) return;
    glfwSetWindowTitle(m_window, title.c_str());
}

bool GLFWWindow::isValid() const
{
    return m_window != nullptr;
}

bool GLFWWindow::shouldClose() const
{
    if (!m_window) return true;
    return glfwWindowShouldClose(m_window);
}

Event<const InputEvent&>& GLFWWindow::windowEvent()
{
    return m_windowEvent;
}
