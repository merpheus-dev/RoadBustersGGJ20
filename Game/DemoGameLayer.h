#pragma once
#include "../Engine/GameLayer.h"
#include "../Utils/Macro.h"
#include "../Engine/GameObject.h"
#include "../Engine/Shader.h"
#include "../Engine/AssetImporter.h"
#include "../Engine/Components/Camera.h"
#include "CameraController.h"
class DemoGameLayer : public GameLayer{
	virtual void Start() override;
	virtual void Update() override;

private:
	GameObject* gameObject;
	Camera* camera;
	ShaderLibrary* library;
	CameraController* cameraController;
};