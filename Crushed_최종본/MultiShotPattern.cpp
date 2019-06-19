#include "MultiShotPattern.h"
#include "myFunction.h"


MultiShotPattern::MultiShotPattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(1.f);

	cnt = 0;
	dir = 0;
	shot = 0;
}


MultiShotPattern::~MultiShotPattern()
{
}


void MultiShotPattern::Update(float eTime) {
	timer->Update(eTime);
	if (timer->isDone)
	{
		for (int i = 0; i < 60; ++i)
		{
			bulletManager->PushBullet(new Bullet(300, 200, DegToRad(i*2 + shot), 700, true));
			bulletManager->PushBullet(new Bullet(800, 500, DegToRad(-(i*2 + shot)), 700, false));
		}
		shot += 50;
		++cnt;

		if (cnt == 20) {
			GameScene::isPatternDone = true;
			cnt = 0;
			dir = 0;
			shot = 0;
		}
	}
}