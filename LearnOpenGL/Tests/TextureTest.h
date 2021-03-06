#pragma once
#include "Test.h"
#include "imgui/imgui.h"

class TextureTest : public Test
{
public: 

	TextureTest();
	~TextureTest();

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
	const char* GetName() { return m_Name; }
private:
	const char* m_Name = "Texture Test";
	float m_Color[4];
};