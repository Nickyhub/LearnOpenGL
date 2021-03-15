#include "VertexArray.h"
#include "Core.h"

VertexArray::VertexArray()
{
	GL_CALL(glGenVertexArrays(1, &m_ID));
	GL_CALL(glBindVertexArray(m_ID));
}

VertexArray::~VertexArray()
{

}

void VertexArray::Bind()
{
	GL_CALL(glBindVertexArray(m_ID));
}

void VertexArray::Unbind()
{
	GL_CALL(glBindVertexArray(0));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	const auto& attributes = layout.GetAttributes();
	unsigned int offset = 0;

	for (int i = 0; i < attributes.size(); i++) {
		GL_CALL(glEnableVertexAttribArray(i));
		GL_CALL(glVertexAttribPointer(i, attributes[i].count, attributes[i].type, attributes[i].normalized, layout.GetStride(), (const void*)offset));
		offset += attributes[i].count * VertexAttribute::GetTypeSize(attributes[i].type);
	}
}
