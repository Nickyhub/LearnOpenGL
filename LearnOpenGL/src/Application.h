#pragma once
#include "GLFW/glfw3.h"

class Application {
public:
	Application();
	int Run();


private:
	GLFWwindow* m_Window;
};