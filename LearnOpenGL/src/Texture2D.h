#pragma once
#include "GL/glew.h"

class Texture2D
{
public:
	Texture2D(const char* filepath, unsigned int format);
	~Texture2D();

	void Bind();
	void Unbind();

private:
	unsigned char* m_Data;
	unsigned int m_ID;
	int m_Width;
	int m_Height;
	int m_NrChannels;
};

