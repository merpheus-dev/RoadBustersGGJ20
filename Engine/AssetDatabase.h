#pragma once
#include <GL/glew.h>
#include <glfw3.h>
#include "Texture.h"
#include "../Utils/Macro.h"
class AssetDatabase {
public:
	static Texture* LoadTexture(const char* file_name);
};
