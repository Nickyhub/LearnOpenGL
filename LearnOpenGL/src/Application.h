#pragma once

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include "GL/glew.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "Tests/ImGuiMenu.h"

class Application {
public:
	Application() = delete;
	~Application() = delete;
	static bool Init();
	static void Shutdown();
	static int Run();
	static GLFWwindow* GetWindow() { return m_Window; }

private:
	inline static GLFWwindow* m_Window;
	inline static ImGuiMenu* m_Menu;
	static void RegisterTests();
};