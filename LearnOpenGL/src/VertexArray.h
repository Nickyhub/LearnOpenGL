#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void Bind();
	void Unbind();
	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	unsigned int* GetID() { return &m_ID; }
private:
	unsigned int m_ID;

};

