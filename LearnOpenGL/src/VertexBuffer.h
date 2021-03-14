#pragma once
#include "GL/glew.h"

class VertexBuffer
{
public:
	VertexBuffer() = default;
	VertexBuffer(float data[], unsigned int size);
	~VertexBuffer();
	void Bind();
	void Unbind();

	unsigned int* GetID() { return &m_ID; }
private:
	unsigned int m_ID;
};

