#include "RandomTopEdgePattern.h"
#include "myFunction.h"



RandomTopEdgePattern::RandomTopEdgePattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(0.f);

	cnt = 0;
}


RandomTopEdgePattern::~RandomTopEdgePattern()
{
}

void RandomTopEdgePattern::Update(float eTime) {
	int rx = rand() % 91;
	int ry = rand() % 91;
	bulletManager->PushBullet(new Bullet(-16, -16, DegToRad(rx), 400, true));
	bulletManager->PushBullet(new Bullet(1280, -16, DegToRad(ry + 90), 400, false));
	cnt++;
	if (cnt == 300) {
		GameScene::isPatternDone = true;
		cnt = 0;
	}
}