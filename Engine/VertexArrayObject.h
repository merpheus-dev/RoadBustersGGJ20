#pragma once
#include <GL/glew.h>
#include "glfw3.h"
#include "Buffer.h"
#include <vector>
#include "Mesh.h"
#include "Material.h"
class VertexArrayObject {
public:
	VertexArrayObject();
	~VertexArrayObject();
	void Bind();
	void UnBind();
	void GenerateBuffers(Mesh* mesh,Material* material);
private:
	GLuint m_id;
	VBO* m_vertexBuffer;
	VBO* m_normalBuffer;
	VBO* m_textureBuffer;
	IBO* m_indexBuffer;
};