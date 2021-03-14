#include "TextureTest.h"

TextureTest::TextureTest()
{
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

	m_VAO = VertexArray();
	m_VBO = VertexBuffer(vertices, sizeof(vertices));
	m_IBO = IndexBuffer(indices, 6);

	m_Layout = VertexBufferLayout();
	m_Layout.Push(3, GL_FLOAT);
	m_Layout.Push(4, GL_FLOAT);
	m_Layout.Push(2, GL_FLOAT);

	m_VAO.AddBuffer(m_VBO, m_Layout);

	m_Texture1 = Texture2D("res/assets/WoodenContainer.jpg", GL_RGB);
	m_Texture2 = Texture2D ("res/assets/SmileyFace.png", GL_RGBA);

	m_Shader = Shader("res/shaders/shader.vs", "res/shaders/shader.fs");
	GL_CALL(glUniform1i(glGetUniformLocation(m_Shader.getShaderID(), "texture1"), 0));
	GL_CALL(glUniform1i(glGetUniformLocation(m_Shader.getShaderID(), "texture2"), 1));

	m_Proj = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	m_Shader.setUniformMat4f("u_MVP", proj);
	m_Shader.Bind();
}

TextureTest::~TextureTest()
{

}

void TextureTest::OnUpdate(float deltaTime)
{

}

void TextureTest::OnRender()
{
	glActiveTexture(GL_TEXTURE0);
	m_Texture1.Bind();
	glActiveTexture(GL_TEXTURE1);
	m_Texture2.Bind();
	m_VAO.Bind();

	float a = (float)glfwGetTime();

	m_Proj = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
	m_Shader.setUniformMat4f("u_mpv", m_Proj);
	GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));

}

void TextureTest::OnImGuiRender()
{
	ImGui::Button("asödlkfj");
}
