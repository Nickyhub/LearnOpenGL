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

	GL_CALL(glEnableVertexAttribArray(0));
	GL_CALL(glVertexAttribPointer(0, attributes[0].count, attributes[0].type, attributes[0].normalized, layout.GetStride(), (const void*)offset));

	offset = 12;

	GL_CALL(glEnableVertexAttribArray(1));
	GL_CALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 36, (const void*)12));

	offset = 28;
	GL_CALL(glEnableVertexAttribArray(2));
	GL_CALL(glVertexAttribPointer(2, attributes[2].count, attributes[2].type, attributes[2].normalized, layout.GetStride(), (const void*)offset));


	/*for (int i = 0; i < attributes.size(); i++) {
		GL_CALL(glEnableVertexAttribArray(i));
		GL_CALL(glVertexAttribPointer(i, attributes[i].count, attributes[i].type, attributes[i].normalized, layout.GetStride(), (const void*)offset));
		offset += attributes[i].count * VertexAttribute::GetTypeSize(attributes[i].type);
	}*/
}
