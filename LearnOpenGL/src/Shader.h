#pragma once

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include <fstream>
#include "Core.h"
#include <GL/glew.h>
#include <sstream>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Shader
{
public:
	Shader() = default;
	Shader(const char* vsfs, const char* fsfs);
	~Shader();
	void Bind();
	void Unbind();

	void setUniform4f(const char* name, float v0, float v1, float v2, float v3);
	void setUniform3f(const char* name, float v0, float v1, float v2);
	void setUniform2f(const char* name, float v0, float v1);
	void setUniform1f(const char* name, float v0);
	void setUniformMat4f(const char* name, const glm::mat4 mvp);
	void setUniform1i(const char* name, int v0);
	unsigned int getShaderID() { return m_ShaderID; };

private:
	unsigned int CreateShaderProgram(std::string vsfs, std::string fsfs);
	unsigned int CompileShader(std::string shadersource, GLenum type);
	std::string ParseShader(const char* filepath);
	unsigned int m_ShaderID;
	std::string m_VertexSource;
	std::string m_FragmentSource;
};

