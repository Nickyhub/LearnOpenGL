#pragma once

#include "Test.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include <functional>
#include <vector>

class ImGuiMenu : public Test
{
public:
	ImGuiMenu() = default;

	ImGuiMenu(GLFWwindow* window) {
		m_Current = this; 
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
	}

	void OnUpdate() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui::Begin("TestMenu");
			if (m_Current == this) {
				for (Test* test : m_Tests) {
					if (ImGui::Button(test->GetName())) {
						m_Current = test;
					}
				}										
			}
			else {
				if (ImGui::Button("<--")) {
					m_Current->Unbind();
					m_Current = this;
				}
				else {
					m_Current->OnUpdate(0.0f);
					m_Current->OnRender();
					m_Current->OnImGuiRender();
				}
			}
		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	template<typename T>
	void RegisterTest() {
		m_Tests.push_back(new T());
	}

private:
	Test* m_Current;
	std::vector<Test*> m_Tests;
};

