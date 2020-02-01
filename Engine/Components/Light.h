#pragma once
#include <glm.hpp>
class Light {
public:
	glm::vec3 Position;
	glm::vec3 Color;
	Light(glm::vec3 position=glm::vec3(0),glm::vec3 color = glm::vec3(1)) : Position(position),Color(color)
	{

	}
};