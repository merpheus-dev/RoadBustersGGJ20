#pragma once
#include "Texture.h"
#include "Shader.h"
#include <vector>
class Material {
public:
	Texture* texture;
	float Shininess = 0.f;
	float ReflectionColor = 0.f;
	float GlossDamping = 0.f;
	float* texCoord;
	unsigned int texCoordSize;
	ShaderLibrary* shader;
};