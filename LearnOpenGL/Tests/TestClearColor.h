#pragma once
#include "Test.h"

class TestClearColor : public Test
{
public:
	TestClearColor();
	~TestClearColor();

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() ;

	const char* GetName() { return m_Name; }

private:
	float m_Color[4];
	const char* m_Name = "ClearColor";
};

