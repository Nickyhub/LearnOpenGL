#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION

#include "Core.h"
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "stb_image.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture2D.h"
#include <Tests/TestClearColor.h>
#include <Tests/TextureTest.h>
#include <Tests/TestMenu.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

void ImGuiNewFrame();
void ImGuiInit(GLFWwindow* window);

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

	//float vertices[] = {
	//	 positions          // colors					// texture coords
	//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,	0.0f, 0.0f, // bottom left
	//	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,	2.0f, 0.0f, // bottom right
	//	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,	2.0f, 2.0f, // top right
	//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 1.0f,	0.0f, 2.0f  // top left 
	//};
	//unsigned int indices[] = {
	//	3, 2, 1,  // second triangle
	//	1, 3, 0   // first triangle
	//};

	//glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);


	//VertexArray vao;

	//VertexBuffer vbo(vertices, sizeof(vertices));
	//IndexBuffer ibo(indices, 6);

	//VertexBufferLayout layout;
	//layout.Push(3, GL_FLOAT);
	//layout.Push(4, GL_FLOAT);
	//layout.Push(2, GL_FLOAT);

	//vao.AddBuffer(vbo, layout);

	//Texture2D texture1("res/assets/WoodenContainer.jpg", GL_RGB);
	//Texture2D texture2("res/assets/SmileyFace.png", GL_RGBA);

	//Shader shader("res/shaders/shader.vs", "res/shaders/shader.fs");
	//GL_CALL(glUniform1i(glGetUniformLocation(shader.getShaderID(), "texture1"), 0));
	//GL_CALL(glUniform1i(glGetUniformLocation(shader.getShaderID(), "texture2"), 1));

	//shader.setUniformMat4f("u_MVP", proj);
	//shader.Bind();

	
	TestClearColor test;
	TextureTest textest;

	TestMenu menu;
	menu.PushTest(test);
	menu.PushTest(textest);

	ImGuiInit(window);
	
	float m_Color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	bool show = false;

	while (!glfwWindowShouldClose(window))
	{
		GL_CALL(glClearColor(menu.GetColor()[0], menu.GetColor()[1], menu.GetColor()[2], menu.GetColor()[3]));
		glClear(GL_COLOR_BUFFER_BIT);

		//glActiveTexture(GL_TEXTURE0);
		//texture1.Bind();
		//glActiveTexture(GL_TEXTURE1);
		//texture2.Bind();
		//vao.Bind();

		//proj = glm::ortho(-1.0f, 1.0f, -1.0f , 1.0f, -1.0f, 1.0f);
		//shader.setUniformMat4f("u_MVP", proj);
		//GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
		ImGuiNewFrame();

		ImGui::Begin("TestMenu");
		menu.ImGuiRender();
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	//glDeleteVertexArrays(1, vao.GetID());
	//glDeleteBuffers(1, vbo.GetID());
	//glDeleteBuffers(1, ibo.GetID());

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void ImGuiInit(GLFWwindow* window) {
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
}

void ImGuiNewFrame() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
}