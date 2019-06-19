#include "HalfPattern.h"
#include "myFunction.h"



HalfPattern::HalfPattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(1.f);

	cnt = 0;
}


HalfPattern::~HalfPattern()
{
}

void HalfPattern::Update(float eTime)
{
	timer->Update(eTime);
	bool halfPatternCheck = rand() % 2;
	bool halfPatternCheck2 = rand() % 2;
	if (timer->isDone)
	{
		for (int i = 0; i < 90; ++i)
		{
			bulletManager->PushBullet(new Bullet(300, 200, DegToRad(i * 2), 400, halfPatternCheck));
			bulletManager->PushBullet(new Bullet(300, 200, DegToRad(-i * 2), 400, !halfPatternCheck));
			bulletManager->PushBullet(new Bullet(900, 500, DegToRad(i * 2), 400, halfPatternCheck2));
			bulletManager->PushBullet(new Bullet(900, 500, DegToRad(-i * 2), 400, !halfPatternCheck2));
		}
		cnt++;
		if (cnt == 8) {
			GameScene::isPatternDone = true;
			cnt = 0;
		}
	}
}