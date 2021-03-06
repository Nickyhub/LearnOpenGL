#pragma once
#include <vector>
#include "GL/glew.h"

struct VertexAttribute {
	unsigned int count;
	unsigned int type;
	bool normalized;

	static unsigned int GetTypeSize(unsigned int type) {
		switch (type) {
		case GL_FLOAT:
			return sizeof(GL_FLOAT);
		case GL_UNSIGNED_INT:
			return sizeof(GL_UNSIGNED_INT);
		case GL_UNSIGNED_BYTE:
			return sizeof(GL_UNSIGNED_BYTE);
		}
		return 0;
	}
};

class VertexBufferLayout
{
public:
	VertexBufferLayout() { m_Stride = 0; }
	~VertexBufferLayout() {}

	std::vector<VertexAttribute> GetAttributes() const { return m_Attributes; }

	void Push(unsigned int count, unsigned int type, bool normalized = false) {
		m_Attributes.push_back({ count, type, normalized });
		m_Stride += count * VertexAttribute::GetTypeSize(type);
	}

	unsigned int GetStride() const { return m_Stride; }

private:
	unsigned int m_Stride;
	std::vector<VertexAttribute> m_Attributes;

};

