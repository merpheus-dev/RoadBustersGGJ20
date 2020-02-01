#pragma once
#include "Mesh.h"
#include "Material.h"
struct RenderObject {
	Material* material;
	Mesh* mesh;
};