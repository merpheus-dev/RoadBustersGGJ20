#include "Window.h"
#include "../Utils/Macro.h"
GLFWwindow*  Window::s_window;
Window::~Window()
{
	glfwDestroyWindow(s_window);
	glfwTerminate();
}

void Window::GenerateWindow()
{
	if (!glfwInit())
		return;

	s_window = glfwCreateWindow(512, 512, "Demo Game", nullptr, nullptr);
	if (!s_window) {
		PRINT("Error while creating window /w GLFW");
		delete this;
	}

	glfwMakeContextCurrent(s_window);

	if (glewInit() != GLEW_OK)
		PRINT("Error while creating window /w GLEW");

	PRINT("Gl Init success"<<(const char*)glGetString(GL_VERSION));
}

bool Window::IsWindowClosed()
{
	return glfwWindowShouldClose(s_window);
}

void Window::Update()
{
	glfwSwapBuffers(s_window);
	glfwPollEvents();
}
