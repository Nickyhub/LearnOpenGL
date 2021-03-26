#pragma once
#include "Test.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "imgui/imgui.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"

class MatricesTest : public Test {
public:
	MatricesTest();

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
	void Unbind() override;
	const char* GetName() override;


private:
	VertexBuffer* m_VBO;
	VertexArray* m_VAO;
	Shader* m_Shader;
	glm::mat4 m_Model;
	glm::mat4 m_View;
	glm::mat4 m_Proj;
	glm::mat4 m_Identity;

	const char* m_Name = "Matrices Test";
	float m_Rot_Degrees;
	float m_Rotation[3];
	float m_Scale[3];
	float m_Translation[3];
};