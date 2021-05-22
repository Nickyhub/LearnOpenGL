#pragma once
#include "Test.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Application.h"
#include "imgui/imgui.h"

class MandelbrotTest : public Test
{
public:
	MandelbrotTest();

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void Unbind() override;
	void OnImGuiRender() override;

	const char* GetName() override;
private:
	Shader* m_Shader;
	VertexArray* m_VAO;
	VertexBuffer* m_VBO;
	IndexBuffer* m_IBO;
	VertexBufferLayout* m_Layout;

	int m_MaxIterations;
	int m_IterationLimit;
	float m_Boundary;
	float m_Zoom;
	float m_CenterX;
	float m_CenterY;
	bool m_Mode;

	unsigned int m_Indices[6] = { 3, 1, 2, 3, 0, 1 };
	const char* m_Name = "Mandelbrot";
};

