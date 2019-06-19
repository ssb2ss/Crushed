#include "ZigzagRoadPattern.h"
#include "myFunction.h"



ZigzagRoadPattern::ZigzagRoadPattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(10.f);

	cnt = 0;
	std = WIDTH / 2;
	speed = 0;
	isLeft = false;
}


ZigzagRoadPattern::~ZigzagRoadPattern()
{
}


void ZigzagRoadPattern::Update(float eTime) {
	timer->Update(eTime);
	if (cnt < 120) {
		bulletManager->PushBullet(new Bullet(cnt * 4 - 16, -16, DegToRad(90), 300, true));
		bulletManager->PushBullet(new Bullet(cnt * 4, -16, DegToRad(90), 300, false));
		bulletManager->PushBullet(new Bullet(WIDTH - (cnt * 4 - 16), -16, DegToRad(90), 300, true));
		bulletManager->PushBullet(new Bullet(WIDTH - (cnt * 4), -16, DegToRad(90), 300, false));
		cnt++;
	}
	else {
		if (isLeft) {
			speed -= 0.3f;
		}
		else {
			speed += 0.3f;
		}
		std += speed;
		if (std <= 620) {
			isLeft = false;
		}
		else if (std >= 660) {
			isLeft = true;
		}
		bulletManager->PushBullet(new Bullet(std - 176, -16, DegToRad(90), 300, true));
		bulletManager->PushBullet(new Bullet(std - 160, -16, DegToRad(90), 300, false));
		bulletManager->PushBullet(new Bullet(std + 176, -16, DegToRad(90), 300, true));
		bulletManager->PushBullet(new Bullet(std + 160, -16, DegToRad(90), 300, false));
	}
	if (timer->isDone) {
		GameScene::isPatternDone = true;
		cnt = 0;
		std = WIDTH / 2;
		speed = 0;
		isLeft = false;
	}
}