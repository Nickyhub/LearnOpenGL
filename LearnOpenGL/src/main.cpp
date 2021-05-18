#include "Core.h"
#include <GLFW/glfw3.h>
#include "Application.h"

int main() 
{
	if (Application::Init()) {
		Application::Run();
	}
	Application::Shutdown();
	return 0;
}