#include "Application.h"

#include <Tests/TestClearColor.h>
#include <Tests/TextureTest.h>
#include <Tests/ImGuiMenu.h>
#include <Tests/CubeTest.h>
#include <Tests/MatricesTest.h>
#include <Tests/CameraTest.h>

Application::Application()
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
	}
	glfwMakeContextCurrent(m_Window);
	if (glewInit() != GLEW_OK) {
		std::cout << "Glew was not initialized du schmok" << std::endl;
	}
	glViewport(0, 0, width, height);

	m_Menu = ImGuiMenu(m_Window);
}

Application::~Application()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

int Application::Run()
{

	while (!glfwWindowShouldClose(m_Window))
	{
		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		m_Menu.OnUpdate();

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
	return 0;
}

void Application::RegisterTests()
{
	m_Menu.RegisterTest<TestClearColor>();
	m_Menu.RegisterTest<TextureTest>();
	m_Menu.RegisterTest<CubeTest>();
	m_Menu.RegisterTest<MatricesTest>();
	m_Menu.RegisterTest<CameraTest>();
}

