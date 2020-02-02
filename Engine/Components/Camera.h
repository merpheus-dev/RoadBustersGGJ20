#pragma once
#include "Transform.h"
#include "glm.hpp"
class Camera {
public:
	Transform transform;
	float fov = 70.0;

	glm::mat4 GetViewMatrix() {
		glm::vec3 direction;
		direction.x = cos(glm::radians(transform.Rotation.y)) * cos(glm::radians(transform.Rotation.x));
		direction.y = sin(glm::radians(transform.Rotation.x));
		direction.z = sin(glm::radians(transform.Rotation.y)) * cos(glm::radians(transform.Rotation.x));

		return glm::lookAt<float>(transform.Position, transform.Position + glm::normalize(direction), glm::vec3(0, 0, -1));
	}

	glm::mat4 GetProjectionMatrix() {
		return glm::perspective<float>(glm::radians(fov), 1200./800., 0.001, 1000.);
	}
};