#pragma once
#include "../Engine/GameLayer.h"
#include "../Utils/Macro.h"
#include "../Engine/GameObject.h"
#include "../Engine/Shader.h"
#include "../Engine/AssetImporter.h"
#include "../Engine/Components/Camera.h"
#include "../Engine/Components/Light.h"
#include "CameraController.h"
class DemoGameLayer : public GameLayer{
	virtual void Start() override;
	virtual void Update() override;

	void SetMVP() {
		library->SetMatrix4("Model", gameObject->transform.GetTransformationMatrix());
		library->SetMatrix4("View", camera->GetViewMatrix());
		library->SetMatrix4("Projection", camera->GetProjectionMatrix());
	}

	void SetLightData() {
		library->SetFloat3("LightPosition", light->Position+glm::vec3(1,1,1));
		library->SetFloat3("LightColor", light->Color);
		library->SetFloat1("AmbientIntensity", m_scene.AmbientLight);
		library->SetFloat1("ReflectionColor", gameObject->render->material->ReflectionColor);
		library->SetFloat1("MaterialShininess", gameObject->render->material->Shininess);
	}
private:
	GameObject* gameObject;
	Camera* camera;
	ShaderLibrary* library;
	CameraController* cameraController;
	Light* light;
};