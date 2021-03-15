#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION

#include "Core.h"
#include <GLFW/glfw3.h>

#include <Tests/TestClearColor.h>
#include <Tests/TextureTest.h>
#include <Tests/ImGuiMenu.h>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

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



	float vertices[] = {
		//positions           // colors					//texture coords
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,	0.0f, 0.0f, // bottom left
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,	2.0f, 0.0f, // bottom right
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,	2.0f, 2.0f, // top right
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 1.0f,	0.0f, 2.0f  // top left 
	};
	unsigned int indices[] = {
		3, 2, 1,  // second triangle
		1, 3, 0   // first triangle
	};

	glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

	VertexArray m_VAO = VertexArray();
	VertexBuffer m_VBO = VertexBuffer(vertices, sizeof(vertices));
	IndexBuffer m_IBO = IndexBuffer(indices, 6);

	VertexBufferLayout m_Layout = VertexBufferLayout();
	m_Layout.Push(3, GL_FLOAT);
	m_Layout.Push(4, GL_FLOAT);
	m_Layout.Push(2, GL_FLOAT);

	m_VAO.AddBuffer(m_VBO, m_Layout);

	Texture2D m_Texture1 = Texture2D("res/assets/WoodenContainer.jpg", GL_RGB);
	Texture2D m_Texture2 = Texture2D("res/assets/SmileyFace.png", GL_RGBA);

	Shader m_Shader = Shader("res/shaders/shader.vs", "res/shaders/shader.fs");
	GL_CALL(glUniform1i(glGetUniformLocation(m_Shader.getShaderID(), "texture1"), 0));
	GL_CALL(glUniform1i(glGetUniformLocation(m_Shader.getShaderID(), "texture2"), 1));

	glm::mat4 m_Proj = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	m_Shader.setUniformMat4f("u_MVP", proj);
	m_Shader.Bind();






	ImGuiMenu menu(window);

	TestClearColor test;
	TextureTest textest;

	menu.RegisterTest<TestClearColor>(test);
	menu.RegisterTest<TextureTest>(textest);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		m_Texture1.Bind();
		glActiveTexture(GL_TEXTURE1);
		m_Texture2.Bind();
		m_VAO.Bind();

		float a = (float)glfwGetTime();

		m_Proj = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
		m_Shader.setUniformMat4f("u_mpv", m_Proj);
		GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));


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