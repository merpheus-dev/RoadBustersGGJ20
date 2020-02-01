#pragma once
//#define GLEW_STATIC ->Define this in define symbols at project properties/cpp/preprocessors
#include "GL/glew.h"
#include "glfw3.h"
class Window {
public:
	void GenerateWindow();
	bool IsWindowClosed();
	void Update();
	~Window();

	static GLFWwindow* s_window;
};