#pragma once
#include "../Engine/UILayer.h"
#include "../Engine/Texture.h"
#include "../Engine/AssetDatabase.h"
class GameUI :public UILayer {
	virtual void Start() override;
	virtual void Render() override;
	Texture* m_texture;
	Texture* m_texture2;
};