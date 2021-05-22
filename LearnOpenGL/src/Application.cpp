#include "Application.h"

#include <chrono>
#include <thread>
#include <Tests/TestClearColor.h>
#include <Tests/TextureTest.h>
#include <Tests/ImGuiMenu.h>
#include <Tests/CubeTest.h>
#include <Tests/MatricesTest.h>
#include <Tests/CameraTest.h>
#include <Tests/MandelbrotTest.h>

bool Application::Init()
{
	//Init stuff
	int width = 1920;
	int height = 1080;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_Window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (m_Window == NULL) {
		std::cout << "Failed to create Window du schmok" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	if (glewInit() != GLEW_OK) {
		std::cout << "Glew was not initialized du schmok" << std::endl;
		return false;
	}
	glViewport(0, 0, width, height);
	glfwSwapInterval(0);
	m_Menu = new ImGuiMenu(m_Window);
	RegisterTests();
	return true;
}

void Application::Shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	if (m_Window) {
		glfwDestroyWindow(m_Window);
	}
	glfwTerminate();
}

int Application::Run()
{	
	std::cout << "Sizeof: " << sizeof(double) << std::endl;
	std::cout << "Sizeoflong: " << sizeof(long double) << std::endl;
	double currentTime = 0.0;
	double lastTime = 0.0;
	int frames = 0;
	std::chrono::high_resolution_clock clock;

	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
	std::chrono::duration<double> elapsed_seconds;
	double oneSecond = 0.0;
	while (!glfwWindowShouldClose(m_Window))
	{
		start = clock.now();
		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		m_Menu->OnUpdate(1.0f);

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
		end = clock.now();

		elapsed_seconds = end - start;
		oneSecond += elapsed_seconds.count();
		if (oneSecond >= 1.0) {
			std::cout << "Elapsed time: " << elapsed_seconds.count() << " s		\n" << "Frames: " << frames << "\n";
			oneSecond = 0;
			frames = 0;
		}

		frames++;
	}
	return 0;
}

void Application::RegisterTests()
{
	m_Menu->RegisterTest<TestClearColor>();
	m_Menu->RegisterTest<TextureTest>();
	m_Menu->RegisterTest<CubeTest>();
	m_Menu->RegisterTest<MatricesTest>();
	m_Menu->RegisterTest<CameraTest>();
	m_Menu->RegisterTest<MandelbrotTest>();
} 