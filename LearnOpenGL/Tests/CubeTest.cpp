#include "CubeTest.h"

CubeTest::CubeTest()
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
	
	layout.Push(3, GL_FLOAT);
	layout.Push(2, GL_FLOAT);
	layout.Push(4, GL_FLOAT);
	
	m_VAO->AddBuffer(*m_VBO, layout);
	
	m_Texture1 = new Texture2D("res/assets/SmileyFace.png", GL_RGBA);
	m_Texture2 = new Texture2D("res/assets/WoodenContainer.jpg", GL_RGB);
	
	m_Model = glm::mat4(1.0f);
	m_Model = glm::rotate(m_Model, glm::radians(55.0f), glm::vec3(1.0f, 0.0f, 0.0f));


	m_Proj = glm::mat4(1.0f);
	m_View = glm::mat4(1.0f);
	
	m_Shader= new Shader("res/shaders/cubeshader.vs", "res/shaders/cubeshader.fs");
	m_Shader->Bind();
}

CubeTest::~CubeTest()
{

}

void CubeTest::OnUpdate(float deltaTime)
{
	
}

void CubeTest::OnRender()
{
	glEnable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	m_Texture1->Bind();
	glActiveTexture(GL_TEXTURE1);
	m_Texture2->Bind();

	m_VAO->Bind();
	
	float a = (float)sin(glfwGetTime());
	m_Model = glm::rotate(m_Model, glm::radians(3.0f * a), glm::vec3(1.0f, 0.0f, 1.0f));
	m_Shader->setUniformMat4f("proj", m_Proj);
	m_Shader->setUniformMat4f("view", m_View);
	m_Shader->setUniformMat4f("model", m_Model);
	m_Shader->setUniform1i("texture1", 0);
	m_Shader->setUniform1i("texture2", 1);
	m_Shader->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void CubeTest::OnImGuiRender()
{
}

const char* CubeTest::GetName()
{
	return m_Name;
}
