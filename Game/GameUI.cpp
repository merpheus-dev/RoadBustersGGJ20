#pragma once
#include "GameUI.h"
void GameUI::Start()
{
	m_texture = AssetDatabase::LoadTexture("Assets/e.jpg");
}

void GameUI::Render()
{
	//ImGui::SetNextWindowSize({ 800, 80 });
	//ImGui::SetNextWindowPos({ 0.f, 0.f }, 0, { 0.f, 0.f });
	ImGui::SetNextWindowPos({ 0.f, 0.f }, 0, { 0.f, 0.f });
	if (ImGui::Begin("Hello",nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
		ImGui::SetNextWindowBgAlpha(0.f);
		ImGui::Button("Hey");
	}
	ImGui::End();
	/*const char* text = "Sa";
	ImGui::GetForegroundDrawList()->AddText(m_font, 48.0, ImGui::GetWindowPos(), 0xffffffff, text);
	ImGui::GetForegroundDrawList()->AddImage((void*)(intptr_t)m_texture->texture_id, ImVec2(20, 100), ImVec2(120, 200));*/
}

