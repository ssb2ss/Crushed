#pragma once
#include "IObject.h"
#include "Sprite.h"
class Bullet :
	public IObject
{
public:
	CSprite *sprite;

	float dir;
	float moveSpeed;
	bool isWhite;

	Bullet(float _x, float _y, float _dir, float _moveSpeed, bool _isWhite);
	~Bullet();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};