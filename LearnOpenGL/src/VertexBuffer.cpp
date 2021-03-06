#include "VertexBuffer.h"
#include "Core.h"

VertexBuffer::VertexBuffer(float data[], unsigned int size)
{
	GL_CALL(glGenBuffers(1, &m_ID));
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
	GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GL_CALL(glDeleteBuffers(1, &m_ID));
}

void VertexBuffer::Bind()
{
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
}

void VertexBuffer::Unbind()
{
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
