#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION

#include "Core.h"
#include <GLFW/glfw3.h>

#include <Tests/TestClearColor.h>
#include <Tests/TextureTest.h>
#include <Tests/ImGuiMenu.h>
#include <Tests/CubeTest.h>
#include <Tests/MatricesTest.h>
#include <Tests/CameraTest.h>
int main() {
	//Init stuff
	int width = 1920;
	int height = 1080;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create Window du schmok" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "Glew was not initialized du schmok" << std::endl;
	}
	glViewport(0, 0, width, height);

	ImGuiMenu menu(window);
	menu.RegisterTest<TestClearColor>();
	menu.RegisterTest<TextureTest>();
	menu.RegisterTest<CubeTest>();
	menu.RegisterTest<MatricesTest>();
	menu.RegisterTest<CameraTest>();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		menu.OnUpdate();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}