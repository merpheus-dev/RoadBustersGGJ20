#pragma once
#include "../Engine/GameLayer.h"
#include "../Utils/Macro.h"
#include "../Engine/GameObject.h"
#include "../Engine/Shader.h"
#include "../Engine/AssetImporter.h"
#include "../Engine/Components/Camera.h"
#include "../Engine/Components/Light.h"
#include "CameraController.h"
#include "RoadMovementPair.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
class DemoGameLayer : public GameLayer {
public:
	virtual void Start() override;
	virtual void Update() override;

	//----------Game Logic----------//

	void ParseLevelData(std::string textData);

	void ConstructScene();

	GameObject* Spawn(const char* meshFile, const char* textureFile);

	int GetRandom(int min, int max) {
		return min + rand() % (max - min + 1);
	}

	void SpawnCars() {
		for (int i = 0; i < 70; i++) {
			std::string a = "Assets/Car" + std::to_string(GetRandom(1, 8)) + ".obj";
			auto* arac = Spawn(a.c_str(), "Assets/buildingAtlas.jpg");
			arac->transform.Rotation.y -= 180;
			arac->transform.Position.y += .05f;
			arac->transform.Position.x = -.12f * (GetRandom(1, 2) == 1 ? -1 : 1);
			arac->transform.Position.z = -99.f;
			m_cars.push_back(arac);
		}
	}

	void RepositionCars() {
		int i = 0;
		for (auto& car : m_cars) {
			car->transform.Position.z = -10.f + i * (GetRandom(3, 8) / 10.);
			i++;
		}
	}

	void MoveCars() {
		for (auto& car : m_cars) {
			if (car->transform.Position.z < -5)
			{
				car->transform.Position = glm::vec3(1) * 99.f;
			}
			else {
				car->transform.Position.z += Time::deltaTime;
			}
		}
	}

	void MoveActiveRoad() {
		if (m_activeRoad == nullptr) return;
		if (glfwGetKey(Window::s_window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			x_tracker -= Time::deltaTime * 5.;
			m_activeRoad->transform.Position.x = (float)((int)(x_tracker / 1) * 1);
		}
		if (glfwGetKey(Window::s_window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			x_tracker += Time::deltaTime * 5.;
			m_activeRoad->transform.Position.x = (float)((int)(x_tracker / 1) * 1);
		}
		if (glfwGetKey(Window::s_window, GLFW_KEY_UP) == GLFW_PRESS) {
			z_tracker -= Time::deltaTime * 5.;
			m_activeRoad->transform.Position.z = (float)((int)(z_tracker / 1) * 1);
		}
		if (glfwGetKey(Window::s_window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			z_tracker += Time::deltaTime * 5.;
			m_activeRoad->transform.Position.z = (float)((int)(z_tracker / 1) * 1);
		}
	}

	void SpawnRoad() {
		std::vector<const char*> roadMeshes;
		roadMeshes.push_back("Assets/FlatRoad1.obj");
		roadMeshes.push_back("Assets/FlatRoad2.obj");
		roadMeshes.push_back("Assets/FlatRoad3.obj");
		roadMeshes.push_back("Assets/FlatRoad4.obj");
		roadMeshes.push_back("Assets/FlatRoad5.obj");
		roadMeshes.push_back("Assets/FlatRoad.obj");
		m_activeRoadIndex = GetRandom(0, roadMeshes.size() - 1);
		m_activeRoad = Spawn(roadMeshes[m_activeRoadIndex], "Assets/Road.jpg");
		x_tracker = 0;
		z_tracker = 0;
	}
	static float s_timeCounter;
private:
	GameObject* m_activeRoad;
	int m_activeRoadIndex = -1;
	float x_tracker = 0;
	float z_tracker = 0;
	std::vector<RoadMovementPair> m_roadData;
	std::vector<int> m_userRoadPlacement;
	bool carSpawned = false;
	std::vector<GameObject*> m_cars;
public:
	//---------Render methods--------//

	void SetMVP(GameObject* gameObject) {
		gameObject->render->material->shader->SetMatrix4("Model", gameObject->transform.GetTransformationMatrix());
		gameObject->render->material->shader->SetMatrix4("View", camera->GetViewMatrix());
		gameObject->render->material->shader->SetMatrix4("Projection", camera->GetProjectionMatrix());
	}

	void SetLightData(GameObject* gameObject) {
		gameObject->render->material->shader->SetFloat3("LightPosition", light->Position + glm::vec3(1, 1, 1));
		gameObject->render->material->shader->SetFloat3("LightColor", light->Color);
		gameObject->render->material->shader->SetFloat1("AmbientIntensity", m_scene.AmbientLight);
		gameObject->render->material->shader->SetFloat1("ReflectionColor", gameObject->render->material->ReflectionColor);
		gameObject->render->material->shader->SetFloat1("MaterialShininess", gameObject->render->material->Shininess);
		gameObject->render->material->shader->SetFloat1("GlossDamping", gameObject->render->material->GlossDamping);
	}
private:
	std::vector<GameObject*> gameObjectList;
	Camera* camera;
	CameraController* cameraController;
	Light* light;
};