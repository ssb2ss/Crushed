#pragma once
#include "IObject.h"
#include "Sprite.h"
#include "Def.h"
class Player :
	public IObject
{
public:
	CSprite *spriteWhite;
	CSprite *spriteBlack;

	int moveSpeed;

	bool isWhite;

	Player();
	~Player();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void Move(float eTime);
	void ColorChange();
};

