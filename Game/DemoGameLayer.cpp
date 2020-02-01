#include "DemoGameLayer.h"
#include "../Engine/Window.h"
#include "../Engine/Time.h"
#include "../Engine/AssetDatabase.h"
void DemoGameLayer::Start()
{
	camera = new Camera();
	cameraController = new CameraController(camera);
	gameObject = new GameObject();

	light = new Light();

	auto pack = AssetImporter::Load("Assets/Zombie9.obj");
	gameObject->render = pack;
	
	auto texture = AssetDatabase::LoadTexture("Assets/Zombie9_CT.jpg");
	gameObject->render->material->texture = texture;

	VertexArrayObject* vao = new VertexArrayObject();
	gameObject->vaoPtr = vao;
	vao->GenerateBuffers(gameObject->render->mesh, gameObject->render->material);
	library = new ShaderLibrary("Shaders/vertexShader.vp", "Shaders/fragmentShader.fp");
	library->BindAttributes();

}

void DemoGameLayer::Update()
{
	Time::Update();
	cameraController->Update();
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	library->Activate();
	gameObject->vaoPtr->Bind();
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glActiveTexture(GL_TEXTURE0);
	SetMVP();
	SetLightData();
	glBindTexture(GL_TEXTURE_2D, gameObject->render->material->texture->texture_id);
	glDrawElements(GL_TRIANGLES, gameObject->render->mesh->vertices_size, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	gameObject->vaoPtr->UnBind();
	library->Deactivate();
}
