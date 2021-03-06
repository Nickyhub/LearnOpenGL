#include "TestMenu.h"

TestMenu::TestMenu() {

}

TestMenu::~TestMenu()
{

}

void TestMenu::PushTest(const Test& test)
{
	m_Current = test;
	m_Tests.push_back(test);
}

void TestMenu::ImGuiRender()
{
	ImGui::BeginTabBar("MyTabBar");


	for (auto& test : m_Tests) {
		if (ImGui::BeginTabItem(test.GetName())) {
			test.OnImGuiRender();
			ImGui::EndTabItem();
		}
	}

	ImGui::EndTabBar();
}
