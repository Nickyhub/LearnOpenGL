#include "MandelbrotTest.h"

MandelbrotTest::MandelbrotTest()
{
	float vertices[] = {
		 1.0f, 0.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f, //oben rechts
		 1.0f, 1.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f, //unten rechts
		-1.0f, 1.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f, //unten links 
		-1.0f, 0.0f, 0.0f,	1.0f, 0.0f, 1.0f, 1.0f//oben links
	};

	m_VBO = new VertexBuffer(vertices, sizeof(vertices));
	m_IBO = new IndexBuffer(m_Indices, 6);
	m_VAO = new VertexArray();

	m_Layout = new VertexBufferLayout();
	m_Layout->Push(3, GL_FLOAT);
	m_Layout->Push(4, GL_FLOAT);

	m_VAO->AddBuffer(*m_VBO, *m_Layout);

	m_Shader = new Shader("res/shaders/mandelbrotshader_vs.glsl", "res/shaders/mandelbrotshader_fs.glsl");
	m_Shader->Bind();
}

void MandelbrotTest::OnUpdate(float deltaTime)
{
}

void MandelbrotTest::OnRender()
{
	m_VAO->Bind();
	m_Shader->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_Indices);
}

void MandelbrotTest::Unbind()
{
}

const char* MandelbrotTest::GetName()
{
	return m_Name;
}
