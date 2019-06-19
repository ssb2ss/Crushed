#include "TwoCirclePattern.h"
#include "myFunction.h"



TwoCirclePattern::TwoCirclePattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(1.5f);
	cnt = 0;
}


TwoCirclePattern::~TwoCirclePattern()
{
}


void TwoCirclePattern::Update(float eTime) {
	timer->Update(eTime);
	if (timer->isDone) {
		for (int i = 0; i < 180; i++) {
			bulletManager->PushBullet(new Bullet(320, HEIGHT / 2, DegToRad(i * 2), 200, true));
			bulletManager->PushBullet(new Bullet(960, HEIGHT / 2, DegToRad(i * 2), 200, false));
		}
		cnt++;
		if (cnt == 7) {
			GameScene::isPatternDone = true;
			cnt = 0;
		}
	}
}