#pragma once
#include "RenderObject.h"
#include "VertexArrayObject.h"
#include "Components/Transform.h"
class GameObject {
public:
	RenderObject* render;
	VertexArrayObject* vaoPtr;
	Transform transform;
};