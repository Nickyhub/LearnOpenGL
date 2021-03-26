#include "Texture2D.h"
#include <iostream>

Texture2D::Texture2D(const char* filepath, unsigned int format)
{
	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	m_Data = stbi_load(filepath, &m_Width, &m_Height, &m_NrChannels, 0);

	if (m_Data) {
		glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Width, 0, format, GL_UNSIGNED_BYTE, m_Data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture du schmok" << std::endl;
	}
	stbi_image_free(m_Data);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &m_ID);
}

void Texture2D::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture2D::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0); 
}
