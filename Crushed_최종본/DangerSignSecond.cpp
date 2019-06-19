#include "DangerSignSecond.h"
#include "myFunction.h"

#define SPR_WIDTH 150

DangerSignSecond::DangerSignSecond()
{
	sprite = new CSprite("images/dangerSign.png");
	sprite->opacity = 0;

	patternNum = -1;

	onActive = false;
	isOpacUp = true;
}

DangerSignSecond::~DangerSignSecond()
{
	delete sprite;
}


void DangerSignSecond::Update(float eTime) {
	PositionSet();
	OpacitySet();
}

void DangerSignSecond::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	sprite->Render(0);
}

void DangerSignSecond::PositionSet() {
	switch (patternNum) {
		case 0:
			sprite->scale.x = 1;
			sprite->scale.y = 4;
			sprite->pos.x = WIDTH - sprite->width;
			sprite->pos.y = 150;
			break;
		case 1:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 960 - sprite->width / 2;
			sprite->pos.y = HEIGHT / 2 - sprite->height / 2;
			break;
		case 2:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH - sprite->width;
			sprite->pos.y = 0;
			break;
		case 3:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH - sprite->width;
			sprite->pos.y = 0;
			break;
		case 5:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 900 - sprite->width / 2;
			sprite->pos.y = 500 - sprite->height / 2;
			break;
		case 7:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 800 - sprite->width / 2;
			sprite->pos.y = 500 - sprite->height / 2;
			break;
		case 8:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 800 - sprite->width / 2;
			sprite->pos.y = 500 - sprite->height / 2;
			break;
		case 9:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH - sprite->width;
			sprite->pos.y = 0;
			break;
		default:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH;
			sprite->pos.y = HEIGHT;
			break;
	}
}

void DangerSignSecond::OpacitySet() {
	if (onActive) {
		if (isOpacUp) {
			sprite->opacity += 2;
			if (sprite->opacity >= 150) {
				sprite->opacity = 150;
				isOpacUp = false;
			}
		}
		else {
			sprite->opacity -= 2;
			if (sprite->opacity <= 0) {
				sprite->opacity = 0;
				isOpacUp = true;
				onActive = false;
			}
		}
	}
}