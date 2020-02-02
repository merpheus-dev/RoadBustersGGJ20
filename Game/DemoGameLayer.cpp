#include "DemoGameLayer.h"
#include "../Engine/Window.h"
#include "../Engine/Time.h"
#include "../Engine/AssetDatabase.h"
#include "../Engine/Events/EventDispatcher.h"
#include "../Utils/TextUtils.h"
float DemoGameLayer::s_timeCounter = 0;

void DemoGameLayer::ParseLevelData(std::string textData)
{
	PRINT("GENERATING LEVEL" << textData);
	///Structure:
	/// ModelDirectory|TextureDir|ModelPos(x,y,z);
	std::istringstream stream(textData);
	std::string line;
	while (std::getline(stream, line)) {

		std::string delimiter = "|";
		size_t pos = 0;
		std::string token;
		std::string modelFile = "";
		std::string textureFile = "";
		glm::vec3 pos_vec = glm::vec3(0);
		int step = 0;
		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			if (step == 0)
				modelFile = token;
			else if (step == 1)
				textureFile = token;

			line.erase(0, pos + delimiter.length());
			step++;
			if (step == 2)
			{
				std::string delimiter2 = ",";
				size_t pos2 = 0;
				std::string token2;
				int vec_index = 0;
				while ((pos2 = line.find(delimiter2)) != std::string::npos) {
					token2 = line.substr(0, pos2);
					if (vec_index < 3) {
						pos_vec[vec_index] = std::stof(token2);
					}
					else {
						break;
					}
					line.erase(0, pos2 + delimiter2.length());
					vec_index++;
				}
			}
		}
		auto* spawned = Spawn(modelFile.c_str(), textureFile.c_str());
		spawned->transform.Position = pos_vec;
	}

}
void DemoGameLayer::ConstructScene()
{
	camera = new Camera();
	camera->transform.Position = glm::vec3(0, 2, 0);
	cameraController = new CameraController(camera);
	camera->transform.Rotation = glm::vec3(330.0, 270., 0.);
	light = new Light();
	light->Position = glm::vec3(2, 2, 2);
	light->Color = glm::vec3(255 / 255., 246 / 255., 212 / 255.) * 2.f;

	auto terrain = Spawn("Assets/terrain.obj", "Assets/terrain.jpg");
	terrain->transform.Position.y = -.3;
	terrain->transform.Scale = glm::vec3(.5);

	std::string levelData = TextUtils::ReadText("Assets/Level1.lavascene");
	ParseLevelData(levelData);
	SpawnCars();
}

GameObject* DemoGameLayer::Spawn(const char* meshFile, const char* textureFile) {
	GameObject* gameObject = new GameObject();
	auto pack = AssetImporter::Load(meshFile);
	gameObject->render = pack;

	gameObject->render->material->Shininess = 0.0;
	auto texture = AssetDatabase::LoadTexture(textureFile);
	gameObject->render->material->texture = texture;

	VertexArrayObject* vao = new VertexArrayObject();
	gameObject->vaoPtr = vao;
	vao->GenerateBuffers(gameObject->render->mesh, gameObject->render->material);
	gameObject->render->material->shader = new ShaderLibrary("Shaders/vertexShader.vp", "Shaders/fragmentShader.fp");
	gameObject->render->material->shader->BindAttributes();
	gameObjectList.push_back(gameObject);
	return gameObject;
}

void DemoGameLayer::Start()
{
	ConstructScene();
	//To-Do: Add ui bindings
	Event* e = new Event(std::bind(&DemoGameLayer::SpawnRoad, this));
	EventDispatcher::Subscribe("GenerateBlock", e);
}

//To-Do: Refactor and implement an abstract render loop to the engine in the future
void DemoGameLayer::Update()
{
	MoveActiveRoad();
	Time::Update();
	s_timeCounter += Time::deltaTime;
	if (s_timeCounter > 5) {
		
		if (!carSpawned) {
			carSpawned = true;
			RepositionCars();
		}
		MoveCars();
	}
	cameraController->Update();
	glClearColor(46 / 255., 176 / 255., 219 / 255., 1);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto& go : gameObjectList) {
		go->render->material->shader->Activate();
		go->vaoPtr->Bind();
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glActiveTexture(GL_TEXTURE0);
		SetMVP(go);
		SetLightData(go);
		glBindTexture(GL_TEXTURE_2D, go->render->material->texture->texture_id);
		glDrawElements(GL_TRIANGLES, go->render->mesh->vertices_size, GL_UNSIGNED_INT, 0);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		go->vaoPtr->UnBind();
		go->render->material->shader->Deactivate();
	}
}
