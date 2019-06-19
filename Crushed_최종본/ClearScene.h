#pragma once
#include "IScene.h"
#include "Sprite.h"
#include "Def.h"
class ClearScene :
	public IScene
{
public:
	bool isOpacUp;

	CSprite *background;
	CSprite *restartButton;

	ClearScene();
	~ClearScene();

	void Update(float eTime);
	void Render();

	void RestartButtonOpacitySet();
	void OnClick();
};

