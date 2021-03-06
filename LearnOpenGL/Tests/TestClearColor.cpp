#include "TestClearColor.h"
#include "imgui/imgui.h"

TestClearColor::TestClearColor() 
	: m_Color{0.2f, 0.3f, 0.8f, 1.0f}
{ 
	m_Name = "Clear Color";
}

TestClearColor::~TestClearColor()
{

}

void TestClearColor::OnUpdate(float deltaTime)
{

}

void TestClearColor::OnRender()
{
	GL_CALL(glClearColor(m_Color[0], m_Color[1], m_Color[2], m_Color[3]));
	GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}

void TestClearColor::OnImGuiRender()
{
	ImGui::ColorEdit4("Clear Color", m_Color);
	ImGui::EndTabItem();	
}
