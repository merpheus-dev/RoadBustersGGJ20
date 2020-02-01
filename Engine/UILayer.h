#pragma once
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "Window.h"
class UILayer {
public:
	virtual void Render() = 0;
	virtual void Start() = 0;
	void Setup() {
		ImGui::CreateContext();
		ImGui_ImplGlfw_InitForOpenGL(Window::s_window, true);
		ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
		ImGui::StyleColorsDark();
		//ImGuiIO io = ImGui::GetIO();
		//m_font = io.Fonts->AddFontFromFileTTF("Assets/Roboto-Regular.ttf", 120.0);
		//Start();
	}

	void LoopBegin() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	// Call it before stopping buffers
	void LoopEnd() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	~UILayer(){
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
protected:
	ImFont* m_font;
};