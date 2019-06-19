#include "Bullet.h"

Bullet::Bullet(float _x, float _y, float _dir, float _moveSpeed, bool _isWhite)
{
	if (_isWhite) {
		sprite = new CSprite("images/bulletWhite.png");
	}
	else {
		sprite = new CSprite("images/bulletBlack.png");
	}
	pos.x = _x;
	pos.y = _y;
	dir = _dir;
	moveSpeed = _moveSpeed;
	isWhite = _isWhite;
}

Bullet::~Bullet()
{
	delete sprite;
}


void Bullet::Update(float eTIme) {
	sprite->Update(eTIme);
	pos.x += cos(dir) * moveSpeed * eTIme;
	pos.y += sin(dir) * moveSpeed * eTIme;
}

void Bullet::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	sprite->Render(&mat);
}