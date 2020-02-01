#pragma once
#include "Window.h"
#include "GameLayer.h"
class LavaEngineSubset {
public:
	static void Run(GameLayer* layer) {
        Window* window = new Window();
        window->GenerateWindow();
        layer->Start();
        while (!window->IsWindowClosed()) {
            layer->Update();
            window->Update();
        }
        delete& window;
	}
};