#pragma once
#include "../Engine/Window.h"
#include "../Engine/Components/Camera.h"
#include "../Engine/Time.h"
class CameraController {
public:
	CameraController(Camera* camera) : m_camera(camera)
	{

	}

	void Update() {
		auto& window = Window::s_window;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			m_camera->transform.Position.z += Time::deltaTime;
		}
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			m_camera->transform.Position.z -= Time::deltaTime;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			m_camera->transform.Position.x -= Time::deltaTime;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			m_camera->transform.Position.x += Time::deltaTime;
		}
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
			m_camera->transform.Position.y -= Time::deltaTime;
		}
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
			m_camera->transform.Position.y += Time::deltaTime;
		}
	}
private:
	Camera* m_camera;
};