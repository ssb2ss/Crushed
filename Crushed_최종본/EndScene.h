#pragma once
#include "IScene.h"
#include "Sprite.h"
#include "Def.h"
class EndScene :
	public IScene
{
public:
	CSprite *background;
	CSprite *restartButton;

	bool isOpacUp;

	EndScene();
	~EndScene();

	void Update(float eTime);
	void Render();

	void RestartButtonOpacitySet();
	void OnClick();
};

