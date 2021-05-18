#pragma once
#include "Test.h"
#include "imgui/imgui.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture2D.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class TextureTest : public Test
{
public: 
	TextureTest();
	~TextureTest();

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
	void Unbind() override;
	const char* GetName() { return m_Name; }
private:
	float m_Transparency;
	unsigned int		m_Indices[6];
	VertexArray*		m_VAO;
	VertexBuffer*		m_VBO;
	IndexBuffer*		m_IBO;
	VertexBufferLayout  m_Layout;
	Texture2D*			m_Texture1;
	Texture2D*			m_Texture2;
	Shader*				m_Shader;
	glm::mat4			m_Proj;
	const char* m_Name = "Texture Test";

};