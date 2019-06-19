#include "NameLeePattern.h"
#include "myFunction.h"


NameLeePattern::NameLeePattern(BulletManager *bulletManager) : Pattern(bulletManager)
{
	timer = new Timer(5.f);

	isDone = false;
}


NameLeePattern::~NameLeePattern()
{
}

void NameLeePattern::Update(float eTime) {
	timer->Update(eTime);
	if (isDone == false) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 50; j++) {
				bulletManager->PushBullet(new Bullet(240 + j * 16, -330 + i * 16, DegToRad(90), 150, nameArray[i][j]));
			}
		}
		isDone = true;
	}
	if (timer->isDone) {
		GameScene::isPatternDone = true;
		isDone = false;
	}
}