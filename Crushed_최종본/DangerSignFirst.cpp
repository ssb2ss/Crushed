#include "DangerSignFirst.h"
#include "myFunction.h"

#define SPR_WIDTH 150

DangerSignFirst::DangerSignFirst()
{
	sprite = new CSprite("images/dangerSign.png");
	sprite->opacity = 0;

	patternNum = -1;

	onActive = false;
	isOpacUp = true;
}

DangerSignFirst::~DangerSignFirst()
{
	delete sprite;
}


void DangerSignFirst::Update(float eTime) {
	PositionSet();
	OpacitySet();
}

void DangerSignFirst::Render(D3DXMATRIX *pmat) {
	IObject::Render(pmat);
	sprite->Render(0);
}

void DangerSignFirst::PositionSet() {
	switch (patternNum) {
		case 0:
			sprite->scale.x = 9;
			sprite->scale.y = 1;
			sprite->pos.x = 0;
			sprite->pos.y = 0;
			break;
		case 1:
		sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 320 - sprite->width / 2;
			sprite->pos.y = HEIGHT / 2 - sprite->height / 2;
			break;
		case 2:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 0;
			sprite->pos.y = 0;
			break;
		case 3:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 0;
			sprite->pos.y = 0;
			break;
		case 4:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH / 2 - sprite->width / 2;
			sprite->pos.y = HEIGHT / 2 - sprite->height / 2;
			break;
			
		case 5:
		sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 300 - sprite->width / 2;
			sprite->pos.y = 200 - sprite->height / 2;
			break;
		case 6:
			sprite->scale.x = 9;
			sprite->scale.y = 5;
			sprite->pos.x = 0;
			sprite->pos.y = 0;
			break;
		case 7:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 300 - sprite->width / 2;
			sprite->pos.y = 200 - sprite->height / 2;
			break;
		case 8:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 300 - sprite->width / 2;
			sprite->pos.y = 200 - sprite->height / 2;
			break;
		case 9:
			sprite->scale.x = 1;
			sprite->scale.y = 1;
			sprite->pos.x = 0;
			sprite->pos.y = 0;
			break;
		case 10:
			sprite->scale.x = 5;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH / 2 - 375;
			sprite->pos.y = 0;
			break;
		case 11:
			sprite->scale.x = 5;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH / 2 - 375;
			sprite->pos.y = 0;
			break;

		case 12:
			sprite->scale.x = 5;
			sprite->scale.y = 1;
			sprite->pos.x = WIDTH / 2 - 375;
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

void DangerSignFirst::OpacitySet() {
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