#pragma once
#include <glm.hpp>
#include <matrix.hpp>
#include <gtx/transform.hpp>
class Transform {
public:
	glm::vec3 Position;
	glm::vec3 Rotation; //Normally, quaternions should be used, forgive me opengl gods
	glm::vec3 Scale;

	Transform(glm::vec3 position = glm::vec3(0),
		glm::vec3 rotation = glm::vec3(0),
		glm::vec3 scale = glm::vec3(1))
		: Position(position), Rotation(rotation), Scale(scale)
	{
	}

	glm::mat4 GetTransformationMatrix()
	{
		glm::mat4 matrix = glm::identity<glm::mat4>();
		matrix = glm::scale(matrix, Scale);
		matrix = glm::rotate(matrix, glm::radians(Rotation.x), glm::vec3(1, 0, 0));
		matrix = glm::rotate(matrix, glm::radians(Rotation.y), glm::vec3(0, 1, 0));
		matrix = glm::rotate(matrix, glm::radians(Rotation.z), glm::vec3(0, 0, 1));
		matrix = glm::translate(matrix, Position);
		return matrix;
	}
};