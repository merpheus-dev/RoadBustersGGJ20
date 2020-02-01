#include "Engine/LavaEngineSubset.h"
#include "Game/DemoGameLayer.h"
int main()
{
	DemoGameLayer* gameLayer = new DemoGameLayer();
	LavaEngineSubset::Run(gameLayer);
}