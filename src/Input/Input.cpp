//
//  Input.cpp
//  Raytracing
//
//  Created by Nathan Thurber on 6/11/22.
//
#include "Input.hpp"
#include "Application.hpp"

#include "glfw3.h"

extern GLFWwindow* g_WindowHandle;

bool Input::IsKeyDown(KeyCode keycode)
{
    GLFWwindow* windowHandle = g_WindowHandle;
    int state = glfwGetKey(windowHandle, (int)keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}
bool Input::IsMouseButtonDown(MouseButton button)
{
    GLFWwindow* windowHandle = g_WindowHandle;
    int state = glfwGetMouseButton(windowHandle, (int)button);
    return state == GLFW_PRESS;
}
glm::vec2 Input::GetMousePosition()
{
    GLFWwindow* windowHandle = g_WindowHandle;
    double x, y;
    glfwGetCursorPos(windowHandle, &x, &y);
    return { (float)x, (float)y };
}
void Input::SetCursorMode(CursorMode mode)
{
    GLFWwindow* windowHandle = g_WindowHandle;
    glfwSetInputMode(windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)mode);
}
