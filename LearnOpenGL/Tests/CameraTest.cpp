#include "CameraTest.h"
#include "Application.h"

CameraTest::CameraTest()
	: m_Proj(glm::mat4(1.0f)),
	m_View(glm::mat4(1.0f)),
	m_Model(glm::mat4(1.0f))
{
	float vertices[] = {
		//position			  /texcoord		//color
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,	0.0f, 0.0f, 1.0f, 1.0f
	};

	m_VAO = new VertexArray();
	m_VBO = new VertexBuffer(vertices, sizeof(vertices));

	VertexBufferLayout layout;

	Camera::Init();

	layout.Push(3, GL_FLOAT);
	layout.Push(2, GL_FLOAT);
	layout.Push(4, GL_FLOAT);

	m_VAO->AddBuffer(*m_VBO, layout);

	m_Texture1 = new Texture2D("res/assets/SmileyFace.png", GL_RGBA);
	m_Texture2 = new Texture2D("res/assets/WoodenContainer.jpg", GL_RGB);


	m_Proj = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
	m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -5.0f));

	m_Shader = new Shader("res/shaders/cubeshader_vs.glsl", "res/shaders/cubeshader_fs.glsl");
	m_Shader->Bind();
	m_Shader->setUniformMat4f("proj", m_Proj);
	m_Shader->setUniformMat4f("view", m_View);
	m_Shader->setUniform1i("texture1", 0);
	m_Shader->setUniform1i("texture2", 1);
}

void CameraTest::OnUpdate(float deltaTime)
{
	m_Shader->setUniformMat4f("view", Camera::GetViewMatrix());
	if (glfwGetKey(Application::GetWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		Camera::ProcessKeyboardInput(CameraDirection::FORWARD, 0.0f);
	}
	if (glfwGetKey(Application::GetWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		Camera::ProcessKeyboardInput(CameraDirection::LEFT, 0.0f);
	}
	if (glfwGetKey(Application::GetWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		Camera::ProcessKeyboardInput(CameraDirection::BACKWARD, 0.0f);
	}
	if (glfwGetKey(Application::GetWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		Camera::ProcessKeyboardInput(CameraDirection::RIGHT, 0.0f);
	}
}

void CameraTest::OnRender()
{
	glEnable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	m_Texture1->Bind();
	glActiveTexture(GL_TEXTURE1);
	m_Texture2->Bind();

	m_VAO->Bind();
	m_Shader->Bind();

	for (int i = 0; i < 15; i++) {
		m_Model = glm::mat4(1.0f);
		m_Model = glm::translate(m_Model, m_Positions[i]);
		m_Model = glm::rotate(m_Model, glm::radians(20.0f * i), glm::vec3(1.0f, 0.3, 0.5f));
		m_Shader->setUniformMat4f("model", m_Model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void CameraTest::OnImGuiRender()
{

}

void CameraTest::Unbind()
{
	m_VBO->Unbind();
	m_Shader->Unbind();
	m_VAO->Unbind();
}

const char* CameraTest::GetName()
{
	return m_Name;
}
