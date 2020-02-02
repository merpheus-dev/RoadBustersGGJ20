#pragma once
#include "GameUI.h"
#include "../Engine/Events/EventDispatcher.h"
#include "../Engine/GameObject.h"
#include "../Game/DemoGameLayer.h"
void GameUI::Start()
{
	m_texture = AssetDatabase::LoadTexture("Assets/add_road_mbutton.jpg");
	m_texture2 = AssetDatabase::LoadTexture("Assets/time.jpg");
}

void GameUI::Render()
{
	ImGui::SetNextWindowSize({ 100, 75 });
	ImGui::SetNextWindowPos({ 600.f, 730.f }, 0, { 0.f, 0.f });
	if (ImGui::Begin("MainWindow",nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
		ImGui::SetNextWindowBgAlpha(0.f);
		if (ImGui::ImageButton((void*)(intptr_t)m_texture->texture_id, ImVec2(64, 64))) {
			EventDispatcher::Dispatch("GenerateBlock");
		}
	}
	ImGui::End();
	/*const char* text = std::to_string(DemoGameLayer::s_timeCounter).c_str();
	ImGui::GetForegroundDrawList()->AddText(m_font, 80.0, ImGui::GetWindowPos(), 0xffffffff, text);
	ImGui::GetForegroundDrawList()->AddImage((void*)(intptr_t)m_texture2->texture_id, ImVec2(70, 100), ImVec2(170, 200));*/
}

