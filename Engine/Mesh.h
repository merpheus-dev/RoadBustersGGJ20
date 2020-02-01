#pragma once
#include <vector>
#include <glm.hpp>
class Mesh {
public:
	float* vertices;
	float* normals;
	unsigned int* indices;

	int vertices_size;
	int normals_size;
	int indices_size;
};