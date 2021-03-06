#pragma once

#include "Core.h"
#include "GL/glew.h"
#include "imgui/imgui.h"
class Test
{
public:
	virtual ~Test() {}
	
	virtual void OnUpdate(float deltaTime) {}
	virtual void OnRender() {}
	virtual void OnImGuiRender() {		
		ImGui::ColorEdit4("Clear Color", m_Color);
	}

	virtual const char* GetName() { return "asdf"; }
protected:
	float m_Color[4] = {};
};

