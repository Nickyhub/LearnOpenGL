#pragma once
#include "Test.h"
#include "Shader.h"
#include "Texture2D.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class CubeTest : public Test
{

public:
	CubeTest();
	~CubeTest();
	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
	const char* GetName() override;


private:
	VertexBuffer* m_VBO;
	Shader* m_Shader;
	VertexArray* m_VAO;
	Texture2D* m_Texture1;
	Texture2D* m_Texture2;

	glm::mat4 m_Proj;
	glm::mat4 m_View;
	glm::mat4 m_Model;

	const char* m_Name = "Cube Test";

};

