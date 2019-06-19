#include "Player.h"
#include "myFunction.h"

Player::Player()
{
	spriteWhite = new CSprite("images/playerWhite.png");
	spriteBlack = new CSprite("images/playerBlack.png");
	pos.x = WIDTH / 2 - spriteWhite->width / 2;
	pos.y = HEIGHT / 2 - spriteWhite->height / 2;

	moveSpeed = 300;

	isWhite = true;
}

Player::~Player()
{
	delete spriteWhite;
	delete spriteBlack;
}


void Player::Update(float eTime) {
	if (isWhite) {
		spriteWhite->Update(eTime);
	}
	else {
		spriteBlack->Update(eTime);
	}
	Move(eTime);
	ColorChange();
}

void Player::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	if (isWhite) {
		spriteWhite->Render(&(this->mat));
	}
	else {
		spriteBlack->Render(&(this->mat));
	}
}


void Player::Move(float eTime) {
	if (MyKeyState('A') > 0 || MyKeyState(VK_LEFT) > 0)
	{
		pos.x -= moveSpeed * eTime;
		if (pos.x < 0)
		{
			pos.x = 0;
		}
		else if (pos.x > WIDTH - spriteWhite->width)
		{
			pos.x = WIDTH - spriteWhite->width;
		}
	}
	else if (MyKeyState('D') > 0 || MyKeyState(VK_RIGHT) > 0)
	{
		pos.x += moveSpeed * eTime;
		if (pos.x < 0)
		{
			pos.x = 0;
		}
		else if (pos.x > WIDTH - spriteWhite->width)
		{
			pos.x = WIDTH - spriteWhite->width;
		}
	}
	if (MyKeyState('W') > 0 || MyKeyState(VK_UP) > 0)
	{
		pos.y -= moveSpeed * eTime;
		if (pos.y < 0)
		{
			pos.y = 0;
		}
		else if (pos.y > HEIGHT - spriteWhite->height)
		{
			pos.y = HEIGHT - spriteWhite->height;
		}
	}
	else if (MyKeyState('S') > 0 || MyKeyState(VK_DOWN) > 0)
	{
		pos.y += moveSpeed * eTime;
		if (pos.y < 0)
		{
			pos.y = 0;
		}
		else if (pos.y > HEIGHT - spriteWhite->height)
		{
			pos.y = HEIGHT - spriteWhite->height;
		}
	}
}

void Player::ColorChange() {
	if (MyKeyState(VK_SPACE) == 1) {
		if (isWhite) {
			isWhite = false;
		}
		else {
			isWhite = true;
		}
	}
}