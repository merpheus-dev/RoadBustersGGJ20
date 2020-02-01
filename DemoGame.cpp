#include "Engine/LavaEngineSubset.h"
#include "Game/DemoGameLayer.h"
#include "Game/GameUI.h"
int main()
{
	DemoGameLayer* gameLayer = new DemoGameLayer();
	GameUI* uiLayer = new GameUI();
	LavaEngineSubset::Run(gameLayer, uiLayer);
}