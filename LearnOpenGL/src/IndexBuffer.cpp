#include "IndexBuffer.h"
#include "Core.h"

IndexBuffer::IndexBuffer(unsigned int indices[], unsigned int count)
{
	m_Count = count;
	GL_CALL(glGenBuffers(1, &m_ID));
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned int), indices, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GL_CALL(glDeleteBuffers(1, &m_ID));
}

void IndexBuffer::Bind()
{
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
}

void IndexBuffer::Unbind()
{
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}