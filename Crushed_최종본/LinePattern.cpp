#include "LinePattern.h"
#include "myFunction.h"

LinePattern::LinePattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(1.5f);
	cnt = 0;
}

LinePattern::~LinePattern()
{
}

void LinePattern::Update(float eTime) {
	timer->Update(eTime);
	if (timer->isDone) {
		for (int i = 0; i * 16 < WIDTH; i++) {
			bulletManager->PushBullet(new Bullet(i * 16, -16, DegToRad(90), 150, true));
		}
		for (int i = 0; i * 16 < HEIGHT; i++) {
			bulletManager->PushBullet(new Bullet(1280, i * 16, DegToRad(180), 150, false));
		}
		cnt++;
		if (cnt == 8) {
			GameScene::isPatternDone = true;
			cnt = 0;
		}
	}
}