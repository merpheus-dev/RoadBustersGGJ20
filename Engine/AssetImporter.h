#pragma once
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "RenderObject.h"
#include <iostream>
class AssetImporter {
public:
	static RenderObject* Load(const char* filePath);
};