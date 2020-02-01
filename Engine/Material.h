#pragma once
#include "Texture.h"
#include <vector>
class Material {
public:
	Texture* texture;
	float* texCoord;
	unsigned int texCoordSize;
};