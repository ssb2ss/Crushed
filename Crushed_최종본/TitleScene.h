#pragma once
#include "IScene.h"
#include "Def.h"
#include "Sprite.h"
#include "myFunction.h"
#include "GameScene.h"
class TitleScene :
	public IScene
{
public:
	bool isOpacUp;
	bool bgOpacUp;

	CSprite *title;
	CSprite *startButton;

	TitleScene();
	~TitleScene();

	void Update(float eTime);
	void Render();

	void StartButtonOpacitySet();
	void BGOpecitySet();
	void OnClick();
};