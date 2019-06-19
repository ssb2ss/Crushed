#include "CrossPattern.h"
#include "myFunction.h"


CrossPattern::CrossPattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(0.5f);

	cnt = 0;
}


CrossPattern::~CrossPattern()
{
}


void CrossPattern::Update(float eTime)
{
	timer->Update(eTime);

	if (timer->isDone) {
		for (int i = 0; i * 16 < WIDTH; i += 5) {
			bulletManager->PushBullet(new Bullet(i * 16, -16, DegToRad(90), 250, true));
			bulletManager->PushBullet(new Bullet(i * 16, HEIGHT + 16, DegToRad(270), 250, true));
		}
		for (int i = 0; i * 16 < HEIGHT; i += 5) {	
			bulletManager->PushBullet(new Bullet(WIDTH, i * 16, DegToRad(180), 250, false));
			bulletManager->PushBullet(new Bullet(-16, i * 16, DegToRad(0), 250, false));
		}
		cnt++;
		if (cnt == 16) {
			GameScene::isPatternDone = true;
			cnt = 0;
		}
	}

}