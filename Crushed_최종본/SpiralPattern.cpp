#include "SpiralPattern.h"
#include "myFunction.h"

SpiralPattern::SpiralPattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(0.f);

	cnt = 0;
	dir = 0;
	shot = 0;
}


SpiralPattern::~SpiralPattern()
{
}


void SpiralPattern::Update(float eTime) {

		for (int i = 0; i < 3; ++i)
		{
			bulletManager->PushBullet(new Bullet(300, 200, DegToRad(i+shot), 700, true));
			bulletManager->PushBullet(new Bullet(800, 500, DegToRad(i+shot), 700, false));
		}
		shot += 10;
		++cnt;

		if (cnt == 100) {
			GameScene::isPatternDone = true;
			cnt = 0;
			dir = 0;
			shot = 0;
		}
	
}
