#include "Shader.h"
#include "../Utils/TextUtils.h"
#include <vector>
#include "../Utils/Macro.h"
ShaderLibrary::ShaderLibrary(const char* vsFile, const char* fsFile)
{
	m_vsId = LoadShader(vsFile, GL_VERTEX_SHADER);
	m_fsId = LoadShader(fsFile, GL_FRAGMENT_SHADER);
	m_programId = glCreateProgram();
	glAttachShader(m_programId, m_vsId);
	glAttachShader(m_programId, m_fsId);
}

ShaderLibrary::~ShaderLibrary()
{
	Deactivate();
	glDetachShader(m_programId, m_vsId);
	glDetachShader(m_programId, m_fsId);
	glDeleteShader(m_vsId);
	glDeleteShader(m_fsId);
	glDeleteProgram(m_programId);
}

void ShaderLibrary::Activate()
{
	glUseProgram(m_programId);
}

void ShaderLibrary::Deactivate()
{
	glUseProgram(0);
}

void ShaderLibrary::BindAttributes()
{
	glBindAttribLocation(m_programId, 0, "position");
	glBindAttribLocation(m_programId, 1, "normal");
	glBindAttribLocation(m_programId, 2, "texCoord");
	glLinkProgram(m_programId);
	glValidateProgram(m_programId);

	//Link check
	GLint program_linked;
	glGetProgramiv(m_programId, GL_LINK_STATUS, &program_linked);
	if (program_linked != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetProgramInfoLog(m_programId, 1024, &log_length, message);
		PRINT(message);
	}
}

void ShaderLibrary::SetFloat1(const char* name, float value)
{
	glUniform1f(GetVariableLocation(name), value);
}

void ShaderLibrary::SetFloat2(const char* name, glm::vec2 value)
{
	glUniform2f(GetVariableLocation(name), value.x,value.y);
}

void ShaderLibrary::SetFloat3(const char* name, glm::vec3 value)
{
	glUniform3f(GetVariableLocation(name), value.x, value.y, value.z);
}

void ShaderLibrary::SetFloat4(const char* name, glm::vec4 value)
{
	glUniform4f(GetVariableLocation(name), value.x, value.y, value.z, value.w);
}
void ShaderLibrary::SetMatrix4(const char* name, glm::mat4 value)
{
	glUniformMatrix4fv(GetVariableLocation(name), 1, GL_FALSE, &value[0][0]);
}

int ShaderLibrary::LoadShader(const char* source, int shaderType)
{
	auto shaderText = TextUtils::ReadText(source);
	int shaderId = glCreateShader(shaderType);
	const GLchar* shaderContext = shaderText.c_str();
	const int shaderLength = shaderText.length();
	glShaderSource(shaderId, 1, &shaderContext, &shaderLength);
	glCompileShader(shaderId);
	int compile_result;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compile_result);
	if (compile_result != GL_TRUE) {
		int maxErrorLength = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxErrorLength);
		std::vector<GLchar> logInfo(maxErrorLength);
		glGetShaderInfoLog(shaderId, maxErrorLength, &maxErrorLength,&logInfo[0]);
		PRINT(&logInfo[0]);
	}

	return shaderId;
}

GLint ShaderLibrary::GetVariableLocation(const char* name)
{
	return glGetUniformLocation(m_programId, name);
}
