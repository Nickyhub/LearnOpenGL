#include "MandelbrotTest.h"

MandelbrotTest::MandelbrotTest()
{
	m_MaxIterations = 100;
	m_IterationLimit = 100;
	m_Zoom = 2.0f;
	m_CenterX = 0.0f;
	m_CenterY = 0.0f;

	float vertices[] = {
		 1.0f, -1.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f, //oben rechts
		 1.0f,  1.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f, //unten rechts
		-1.0f,  1.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f, //unten links 
		-1.0f, -1.0f, 0.0f,	1.0f, 0.0f, 1.0f, 1.0f//oben links
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
	std::cout << "Sizeof long double: " << sizeof(long long) << std::endl;
	std::cout << "Sizeof double: " << sizeof(double) << std::endl;
}

void MandelbrotTest::OnUpdate(float deltaTime)
{
	if (glfwGetKey(Application::GetWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
		m_Zoom = (m_Zoom * 1.02f) * deltaTime;
		if (m_Zoom > 5.0f) {
			m_Zoom = 5.0f;
		}
	}
	else if (glfwGetKey(Application::GetWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
		m_Zoom = (m_Zoom * 0.98f) * deltaTime;
	}
	else if (glfwGetKey(Application::GetWindow(), GLFW_KEY_LEFT) == GLFW_PRESS) {
		m_CenterX = (m_CenterX - 0.015f * m_Zoom) * deltaTime;
		if (m_CenterX > 5.0f) {
			m_CenterX = 5.0f;
		}
	}
	else if (glfwGetKey(Application::GetWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS) {
		m_CenterX = (m_CenterX + 0.015f * m_Zoom) * deltaTime;
		if (m_CenterX < -5.0f) {
			m_CenterX = -5.0f;
		}
	}
}

void MandelbrotTest::OnRender()
{ 
	m_VAO->Bind();
	m_Shader->Bind();
	m_Shader->setUniform1i("MAX_ITERATIONS", m_MaxIterations);
	m_Shader->setUniform1f("zoom", m_Zoom);
	m_Shader->setUniform1f("center_x", m_CenterX);
	m_Shader->setUniform1f("center_y", m_CenterY);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_Indices);
}

void MandelbrotTest::Unbind()
{
}

const char* MandelbrotTest::GetName()
{
	return m_Name;
}

void MandelbrotTest::OnImGuiRender()
{
	ImGui::InputInt("Iterationslimit", &m_IterationLimit);
	ImGui::SliderInt("Maximale Iteration", &m_MaxIterations, 1, m_IterationLimit);
}
