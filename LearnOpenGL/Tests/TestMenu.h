#pragma once
#include <vector>
#include "Test.h"
#include "imgui/imgui.h"

class TestMenu {
public:
	TestMenu();
	~TestMenu();

	void PushTest(const Test& test);
	void ImGuiRender();
	float* GetColor() { return m_Color; }
	Test GetCurrent() { return m_Current; }

private:
	Test m_Current{};
	float m_Color[4] = {};
	std::vector<Test> m_Tests;
};