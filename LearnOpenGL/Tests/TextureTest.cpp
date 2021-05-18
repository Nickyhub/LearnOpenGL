#include "TextureTest.h"

TextureTest::TextureTest()
	: m_Indices{3, 2, 1, 1, 3, 0}
{
	float vertices[] = {
		//positions           // colors					//texture coords
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,	0.0f, 0.0f, // bottom left
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,	2.0f, 0.0f, // bottom right
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,	2.0f, 2.0f, // top right
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 1.0f,	0.0f, 2.0f  // top left 
	};

	glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

	m_VAO = new VertexArray();
	m_VBO = new VertexBuffer(vertices, sizeof(vertices));
	m_IBO = new IndexBuffer(m_Indices, 6);

	m_Layout = VertexBufferLayout();
	m_Layout.Push(3, GL_FLOAT);
	m_Layout.Push(4, GL_FLOAT);
	m_Layout.Push(2, GL_FLOAT);

	m_VAO->AddBuffer(*m_VBO, m_Layout);

	m_Texture1 = new Texture2D("res/assets/WoodenContainer.jpg", GL_RGB);
	m_Texture2 = new Texture2D("res/assets/SmileyFace.png", GL_RGBA);

	m_Shader = new Shader("res/shaders/textureshader_vs.glsl", "res/shaders/textureshader_fs.glsl");
	GL_CALL(glUniform1i(glGetUniformLocation(m_Shader->getShaderID(), "texture1"), 0));
	GL_CALL(glUniform1i(glGetUniformLocation(m_Shader->getShaderID(), "texture2"), 1));

	glm::mat4 m_Proj = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	m_Shader->setUniformMat4f("u_MVP", proj);
	m_Shader->Bind();
}

TextureTest::~TextureTest()
{
	delete m_Shader;
	delete m_Texture1;
	delete m_Texture2;
	delete m_VAO;
	delete m_VBO;
	delete m_IBO;
}

void TextureTest::OnUpdate(float deltaTime)
{

}

void TextureTest::OnRender()
{
	glDisable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	m_Texture1->Bind();
	glActiveTexture(GL_TEXTURE1);
	m_Texture2->Bind();
	m_VAO->Bind();

	float a = (float)glfwGetTime();

	m_Shader->Bind();
	m_Shader->setUniform1i("texture1", 0);
	m_Shader->setUniform1i("texture2", 1);
	m_Proj = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
	m_Shader->setUniform2f("transparency", m_Transparency, 0.0f);
	m_Shader->setUniformMat4f("u_MPV", m_Proj);
	
	GL_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
}

void TextureTest::OnImGuiRender()
{
	ImGui::SliderFloat("Transparency", &m_Transparency, 0.0f, 1.0f);
}

void TextureTest::Unbind()
{
	m_Shader->Unbind();
	m_VAO->Unbind();
	m_VBO->Unbind();
	m_Texture1->Unbind();
	m_Texture2->Unbind();
}
