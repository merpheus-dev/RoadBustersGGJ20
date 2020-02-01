#include "Buffer.h"
VBO::VBO(float* arrayObject, int count)
{
	glGenBuffers(1, &m_id);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, (const void*)arrayObject, GL_STATIC_DRAW);
}
VBO::~VBO()
{
	glDeleteBuffers(1, &m_id);
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

IBO::IBO(unsigned int* indices, int count)
{
	glGenBuffers(1, &m_id);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, (const void*)indices, GL_STATIC_DRAW);
}

IBO::~IBO()
{
	glDeleteBuffers(1, &m_id);
}

void IBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void IBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
