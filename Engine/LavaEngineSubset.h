#pragma once
#include "Window.h"
#include "GameLayer.h"
#include "UILayer.h"
#include "AssetDatabase.h"
class LavaEngineSubset {
public:
	static void Run(GameLayer* game_layer,UILayer* ui_layer) {
        Window* window = new Window();
        window->GenerateWindow();
        ui_layer->Setup();
        game_layer->Start();
        while (!window->IsWindowClosed()) {
            ui_layer->LoopBegin();
            ui_layer->Render();
            game_layer->Update();
            ui_layer->LoopEnd();
            window->Update();
        }
        delete window;
        delete ui_layer;
	}
};