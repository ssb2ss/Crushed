#include "CenterRotationPattern.h"
#include "myFunction.h"

CenterRotationPattern::CenterRotationPattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(2.f);

	cnt = 0;
	dir = 0;
	isRight = true;
	plusSpeed = 0;
}

CenterRotationPattern::~CenterRotationPattern()
{
}


void CenterRotationPattern::Update(float eTime) {
	timer->Update(eTime);
	bulletManager->PushBullet(new Bullet(WIDTH / 2, HEIGHT / 2, DegToRad(dir), 500, true));
	bulletManager->PushBullet(new Bullet(WIDTH / 2, HEIGHT / 2, DegToRad(dir + 180), 500, false));
	if (isRight) {
		plusSpeed++;
		dir += plusSpeed;
	}
	else {
		plusSpeed--;
		dir += plusSpeed;
	}
	if (timer->isDone) {
		if (isRight) {
			isRight = false;
		}
		else {
			isRight = true;
		}
		cnt++;
	}
	if (cnt == 5) {
		GameScene::isPatternDone = true;
		dir = 0;
		isRight = true;
		plusSpeed = 0;
		cnt = 0;
	}
}