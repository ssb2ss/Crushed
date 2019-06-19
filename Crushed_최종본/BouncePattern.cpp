#include "BouncePattern.h"
#include "myFunction.h"

BouncePattern::BouncePattern(BulletManager *bulletManager) : Pattern(bulletManager)
{

	timer = new Timer(1.5f);
	cnt = 0;

}



BouncePattern::~BouncePattern()
{

}

void BouncePattern::Update(float eTime)
{
	int rx = rand() % 81;
	int ry = rand() % 81;
	bulletManager->PushBullet(new Bullet(10, 10 ,DegToRad(rx + 10), 500, true));
	bulletManager->PushBullet(new Bullet(WIDTH - 26, 10, DegToRad(ry + 90), 500, false));
	cnt++;
	if (cnt == 200) {
		GameScene::isPatternDone = true;
		cnt = 0;
	}
}
