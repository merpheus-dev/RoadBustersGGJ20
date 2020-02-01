#pragma once
#include <gl/glew.h>
#include <glfw3.h>
#include <glm.hpp>
class ShaderLibrary {
public:
	ShaderLibrary(const char* vsFile,const char* fsFile);
	~ShaderLibrary();
	void Activate();
	void Deactivate();
	void BindAttributes();
	void SetFloat1(const char* name, float value);
	void SetFloat2(const char* name, glm::vec2 value);
	void SetFloat3(const char* name, glm::vec3 value);
	void SetFloat4(const char* name, glm::vec4 value);
	void SetMatrix4(const char* name, glm::mat4 value);
private:
	int LoadShader(const char* source, int shaderType);
	GLint GetVariableLocation(const char* name);

	int m_vsId;
	int m_fsId;
	int m_programId;
};