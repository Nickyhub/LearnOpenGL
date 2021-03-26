#pragma once
#define GLEW_STATIC
#include "GL/glew.h"

#include <iostream>
#include <GLFW/glfw3.h>
#include "Tests/ImGuiMenu.h"

class Application {
public:
	Application();
	~Application();
	int Run();
	GLFWwindow* getWindow() { return m_Window; }

private:
	void RegisterTests();
	GLFWwindow* m_Window;
	ImGuiMenu m_Menu;
};