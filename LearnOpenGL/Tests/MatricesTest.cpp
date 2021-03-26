#include "MatricesTest.h"

MatricesTest::MatricesTest()
	: m_Model(glm::mat4(1.0f)),
	  m_Proj(glm::mat4(1.0f)),
	  m_View(glm::mat4(1.0f)),
	  m_Identity(glm::mat4(1.0f)),
	  m_Rotation{ 0.0f, 0.0f, 1.0f },
	  m_Scale{1.0f, 1.0f, 1.0f},
	  m_Translation{0.0f, 0.0f, 0.0f},
	  m_Rot_Degrees(0.0f)
{
	float vertices[] = {
		//position			  	//color
		-0.5f, -0.5f, -0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f, -0.5f,  0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,

		 0.5f,  0.5f,  0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  	0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  	1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  	0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  	0.0f, 0.0f, 1.0f, 1.0f
	};

	m_VBO = new VertexBuffer(vertices, sizeof(vertices));
	m_VAO = new VertexArray();

	VertexBufferLayout layout;
	layout.Push(3, GL_FLOAT);
	layout.Push(4, GL_FLOAT);

	m_VAO->AddBuffer(*m_VBO, layout);

	m_Shader = new Shader ("res/shaders/matrices.vs", "res/shaders/matrices.fs");
}

void MatricesTest::OnUpdate(float deltaTime)
{

}

void MatricesTest::OnRender()
{
	glEnable(GL_DEPTH_TEST);
	m_Shader->Bind();
	m_VAO->Bind();

	m_Proj = glm::rotate(m_Identity, glm::radians(m_Rot_Degrees), glm::vec3(m_Rotation[0], m_Rotation[1], m_Rotation[2]));
	m_Model = glm::scale(m_Identity, glm::vec3(m_Scale[0], m_Scale[1], m_Scale[2]));
	m_View = glm::translate(m_Identity, glm::vec3(m_Translation[0], m_Translation[1], m_Translation[2]));

	m_Shader->setUniformMat4f("proj", m_Proj);
	m_Shader->setUniformMat4f("model", m_Model);
	m_Shader->setUniformMat4f("view", m_View);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void MatricesTest::OnImGuiRender()
{
	ImGui::SliderFloat3("Scale", m_Scale, 0.0f, 10.0f);
	ImGui::SliderFloat3("Translation", m_Translation, -1.0f, 1.0f);
	ImGui::SliderFloat3("Rotation", m_Rotation, 0.0f, 5.0f);
	ImGui::SliderFloat("Rotate degrees", &m_Rot_Degrees, 0.0f, 360.0f);
}

void MatricesTest::Unbind()
{

}

const char* MatricesTest::GetName()
{
	return m_Name;
}
