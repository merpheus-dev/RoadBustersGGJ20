#pragma once
#include <GL/glew.h>
#include <glfw3.h>
class Buffer {
public:
	virtual ~Buffer() = default;
	virtual void Bind() = 0;
	virtual void Unbind() = 0;
protected:
	GLuint m_id;
};

class VBO : public Buffer {
public:
	VBO(float* arrayObject,int count);
	~VBO() override;
	virtual void Bind() override;
	virtual void Unbind() override;
};

class IBO : public Buffer {
public:
	IBO(unsigned int* indices,int count);
	~IBO() override;
	virtual void Bind() override;
	virtual void Unbind() override;
};