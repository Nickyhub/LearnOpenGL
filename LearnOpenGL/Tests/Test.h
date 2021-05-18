#pragma once

#include "Core.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Test
{
public:
	virtual ~Test() {}
	
	virtual void OnUpdate(float deltaTime) {}
	virtual void OnRender() {}
	virtual void OnImGuiRender() {}
	virtual void Unbind() {}

	virtual const char* GetName() { return "asdf"; }
};

