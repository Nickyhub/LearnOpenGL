#pragma once
#include "Test.h"
#include "Texture2D.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "imgui/imgui.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Camera.h"

class CameraTest : public Test
{
public:
	CameraTest();
	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
	void Unbind() override;
	const char* GetName() override;
private:
	glm::mat4 m_Model;
	glm::mat4 m_View;
	glm::mat4 m_Proj;
	glm::vec3 m_Positions[15] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f),
		glm::vec3(-5.0f, 4.0f, 1.0f),
		glm::vec3(3.0f, -2.5f, 1.3f),
		glm::vec3(10.0f, 5.0f, -3.0f),
		glm::vec3(0.0f, 3.0f, 10.0f),
		glm::vec3(-3.0f, 4.0f, -10.0f)
	};

	VertexBuffer* m_VBO;
	VertexArray* m_VAO;
	Shader* m_Shader;
	Texture2D* m_Texture1;
	Texture2D* m_Texture2;
	const char* m_Name = "Camera Test";
};

