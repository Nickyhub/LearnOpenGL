#pragma once
#include "GL/glew.h"

class IndexBuffer
{
public:
	IndexBuffer() = default;
	IndexBuffer(unsigned int indices[], unsigned int count);
	~IndexBuffer();
	void Bind();
	void Unbind();

	unsigned int* GetID() { return &m_ID; }
	unsigned int GetCount() { return m_Count; }
private:
	unsigned int m_ID;
	unsigned int m_Count;
};

