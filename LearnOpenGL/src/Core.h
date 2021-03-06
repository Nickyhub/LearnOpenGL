#pragma once
#include <GL/glew.h>
#include <iostream>

#ifdef _DEBUG
static void GLCLearError() {
	while (glGetError() != GL_NO_ERROR);
}
static bool GLLogCall(const char* function) {
	while (GLenum error = glGetError()) {
		std::cout << "OpenGL Error: " << function << error << std::endl;
		return false;
	}
	return true;
}

#define ASSERT(x) if(!x) {__debugbreak();}
#define GL_CALL(x) GLCLearError();\
x;\
GLLogCall(#x);

#else
#define GL_CALL(x) x;
#endif