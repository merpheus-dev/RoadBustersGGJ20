#pragma once
#include "Transform.h"
#include "glm.hpp"
class Camera {
public:
	Transform transform;
	float fov = 70.0;

	glm::mat4 GetViewMatrix() {
		return glm::lookAt<float>(transform.Position, transform.Position + glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
	}

	glm::mat4 GetProjectionMatrix() {
		return glm::perspective<float>(glm::radians(fov), 1.0, 0.001, 1000.);
	}
};