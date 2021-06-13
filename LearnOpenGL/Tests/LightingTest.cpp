#include "LightingTest.h"

LightingTest::LightingTest()
	: m_Proj(glm::mat4(1.0f)),
	m_View(glm::mat4(1.0f)),
	m_Model(glm::mat4(1.0f))
{
	float vertices[] = {
		//position			
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
	};

	m_VAO = new VertexArray();
	m_VBO = new VertexBuffer(vertices, sizeof(vertices));

	m_RGB[0] = 1.0f;
	m_RGB[1] = 1.0f;
	m_RGB[2] = 1.0f;

	m_Layout = new VertexBufferLayout();
	m_Layout->Push(3, GL_FLOAT);

	m_VAO->AddBuffer(*m_VBO, *m_Layout);
	m_ShaderLightCube = new Shader("res/shaders/lightingshader_vs.glsl", "res/shaders/lightingshadercube_fs.glsl");
	m_ShaderLight = new Shader("res/shaders/lightingshader_vs.glsl", "res/shaders/lightingshader_fs.glsl");
	m_ShaderLight->Bind();

	m_Proj = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);

	Camera::Init();

}


void LightingTest::OnUpdate(float deltaTime)
{
	m_ShaderLight->Bind();
	m_ShaderLight->setUniformMat4f("view", Camera::GetViewMatrix());
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

void LightingTest::OnRender()
{
	glEnable(GL_DEPTH_TEST);
	m_VAO->Bind();
	m_ShaderLight->Bind();
	m_ShaderLight->setUniformMat4f("proj", m_Proj);

	m_ShaderLight->setUniform3f("objectcolor", 0.0f, 0.5f, 1.0f);
	m_ShaderLight->setUniform3f("lightcolor", m_RGB[0], m_RGB[1], m_RGB[2]);

	m_Model = glm::mat4(1.0f);
	m_ShaderLight->setUniformMat4f("model", m_Model);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	m_ShaderLightCube->Bind();
	m_ShaderLightCube->setUniformMat4f("proj", m_Proj);

	m_ShaderLightCube->setUniformMat4f("view", Camera::GetViewMatrix());

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(1.2f, 1.0f, 2.0f));
	model = glm::scale(model, glm::vec3(0.2f));
	m_ShaderLightCube->setUniformMat4f("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void LightingTest::OnImGuiRender()
{
	ImGui::SliderFloat3("RGB", m_RGB, 0.0f, 1.0f);
}

void LightingTest::Unbind()
{

}

const char* LightingTest::GetName()
{
	return m_Name;
}
