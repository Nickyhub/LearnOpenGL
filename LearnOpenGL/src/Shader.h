#pragma once
#define GLEW_STATIC

#include <fstream>
#include "Core.h"
#include <GL/glew.h>
#include <sstream>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Shader
{
public:
	Shader(const char* vsfs, const char* fsfs);
	~Shader() = default;
	void Bind();
	void Unbind();
	unsigned int CreateShaderProgram(std::string vsfs, std::string fsfs);
	unsigned int CompileShader(std::string shadersource, GLenum type);
	std::string ParseShader(const char* filepath);
	unsigned int getShaderID() { return m_ShaderID; };

	void setUniform4f(const char* name, float v0, float v1, float v2, float v3);
	void setUniformMat4f(const char* name, const glm::mat4 mvp);

private:
	unsigned int m_ShaderID;
	std::string m_VertexSource;
	std::string m_FragmentSource;
};

