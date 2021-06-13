#pragma once
#include "Test.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Camera.h"
#include "Application.h"

#include "gtc/matrix_transform.hpp"

class LightingTest : public Test
{
public:
	LightingTest();
	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
	void Unbind() override;
	const char* GetName() override;
private:
	VertexBuffer*		m_VBO;
	VertexArray*		m_VAO;
	VertexBufferLayout* m_Layout;
	Shader*				m_ShaderLight;
	Shader*				m_ShaderLightCube;
	glm::mat4			m_Proj;
	glm::mat4			m_View;
	glm::mat4			m_Model;

	float				m_RGB[3];
	const char* m_Name = "LightingTest";
};

