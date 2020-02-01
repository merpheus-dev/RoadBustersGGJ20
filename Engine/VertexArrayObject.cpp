#include "VertexArrayObject.h"
VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &m_id);
}

VertexArrayObject::~VertexArrayObject()
{
	glDeleteVertexArrays(1, &m_id);
}

void VertexArrayObject::Bind()
{
	glBindVertexArray(m_id);
}

void VertexArrayObject::UnBind()
{
	glBindVertexArray(0);
}

void VertexArrayObject::GenerateBuffers(Mesh* mesh,Material* material)
{
	float* vertices = &(mesh->vertices)[0];
	float* normals = &(mesh->normals)[0];
	unsigned int* indices = &(mesh->indices)[0];

	float* texCoords = &(material->texCoord)[0];

	Bind();
	m_vertexBuffer = new VBO(vertices,mesh->vertices_size);
	m_vertexBuffer->Bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	m_normalBuffer = new VBO(normals, mesh->normals_size);
	m_normalBuffer->Bind();
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	m_textureBuffer = new VBO(texCoords, material->texCoordSize);
	m_textureBuffer->Bind();
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	m_indexBuffer = new IBO(indices, mesh->indices_size);
	m_indexBuffer->Bind();
}