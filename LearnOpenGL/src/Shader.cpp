#include "Shader.h"

Shader::Shader(const char* vsfs, const char* fsfs){
	m_VertexSource = ParseShader(vsfs);
	m_FragmentSource = ParseShader(fsfs);

	m_ShaderID = CreateShaderProgram(m_VertexSource, m_FragmentSource);
	GL_CALL(glUseProgram(m_ShaderID));
}

Shader::~Shader()
{
	glDeleteProgram(m_ShaderID);
}

void Shader::Bind()
{
	GL_CALL(glUseProgram(m_ShaderID));
}

void Shader::Unbind()
{
	glUseProgram(0);
}

unsigned int Shader::CreateShaderProgram(std::string vsfs, std::string fsfs)
{
	unsigned int vs, fs;

	vs = CompileShader(vsfs, GL_VERTEX_SHADER);
	fs = CompileShader(fsfs, GL_FRAGMENT_SHADER);

	unsigned int program;
	program = glCreateProgram();
	GL_CALL(glAttachShader(program, vs));
	GL_CALL(glAttachShader(program, fs));
	GL_CALL(glLinkProgram(program));
	GL_CALL(glValidateProgram(program));

	return program;
}

unsigned int Shader::CompileShader(std::string shadersource, GLenum type)
{
	unsigned int shader = glCreateShader(type);
	const char* source = shadersource.c_str();
	GL_CALL(glShaderSource(shader, 1, &source, nullptr));
	GL_CALL(glCompileShader(shader));

	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(shader, length, &length, message);
		
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? " vertex" : " fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(shader);
		return 0;
	}
	return shader;
}

std::string Shader::ParseShader(const char* filepath)
{
	std::ifstream input;
	input.open(filepath);
	if (input.fail()) {
		std::cout << "Failed to load file to schmok" << std::endl;
	}
	std::string line;
	std::stringstream ss;
	while (getline(input, line)) {
		ss << line << "\n";
	}
	return ss.str();
}

void Shader::setUniform4f(const char* name, float v0, float v1, float v2, float v3)
{
	unsigned int uniform_location = glGetUniformLocation(m_ShaderID, name);
	GL_CALL(glUniform4f(uniform_location, v0, v1, v2, v3));
}

void Shader::setUniform3f(const char* name, float v0, float v1, float v2)
{
	unsigned int uniform_location = glGetUniformLocation(m_ShaderID, name);
	GL_CALL(glUniform3f(uniform_location, v0, v1, v2));
}

void Shader::setUniform2f(const char* name, float v0, float v1)
{
	unsigned int uniform_location = glGetUniformLocation(m_ShaderID, name);
	GL_CALL(glUniform2f(uniform_location, v0, v1));
}

void Shader::setUniform1f(const char* name, float v0)
{
	unsigned int uniform_location = glGetUniformLocation(m_ShaderID, name);
	GL_CALL(glUniform1f(uniform_location, v0));
}

void Shader::setUniformMat4f(const char* name, const glm::mat4 mvp)
{
	unsigned int uniform_location = glGetUniformLocation(m_ShaderID, name);
	GL_CALL(glUniformMatrix4fv(uniform_location, 1, GL_FALSE, &mvp[0][0]));
}

void Shader::setUniform1i(const char* name, int v0)
{
	unsigned int uniform_location = glGetUniformLocation(m_ShaderID, name);
	GL_CALL(glUniform1i(uniform_location, v0));
}
