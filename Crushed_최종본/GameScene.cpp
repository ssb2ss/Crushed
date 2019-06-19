#include "GameScene.h"
#include "myFunction.h"

bool GameScene::isPatternDone = true;

GameScene::GameScene()
{
	background = new CSprite("images/background.png");
	player = new Player();
	bulletManager = new BulletManager();

	isRandomPatternSet = true;
	randomPatternSet = -1;
	randomPattern = -1;

	patternBreakTimer = new Timer(2.5f);

	dangerSignFirst = new DangerSignFirst();
	dangerSignSecond = new DangerSignSecond();

	PatternDefine();

	
}

GameScene::~GameScene()
{
	delete background;
	delete player;
	delete bulletManager;
	delete patternBreakTimer;
	delete dangerSignFirst;
	delete dangerSignSecond;
}


void GameScene::Update(float eTime) {
	background->Update(eTime);
	player->Update(eTime);
	bulletManager->Update(eTime);
	OnBulletScreenOut();
	CollisionCheck();
	if (player->isDelete) {
		isPatternDone = true;
		ChangeScene(new EndScene());
		return;
	}
	dangerSignFirst->Update(eTime);
	dangerSignSecond->Update(eTime);
	SetPattern(eTime);

	if (randomPattern == 9)
	{
		BounceCheck();
	}
	
}

void GameScene::Render() {
	background->Render(0);
	player->Render(0);
	bulletManager->Render(0);
	dangerSignFirst->Render(0);
	dangerSignSecond->Render(0);
}


void GameScene::PatternDefine() {
	nameHongPattern = new NameHongPattern(bulletManager);
	nameGuakPattern = new NameGuakPattern(bulletManager);
	nameLeePattern = new NameLeePattern(bulletManager);
	linePattern = new LinePattern(bulletManager);
	twoCirclePattern = new TwoCirclePattern(bulletManager);
	randomTopEdgePattern = new RandomTopEdgePattern(bulletManager);
	zigzagRoadPattern = new ZigzagRoadPattern(bulletManager);
	centerRotationPattern = new CenterRotationPattern(bulletManager);
	halfPattern = new HalfPattern(bulletManager);
	crossPattern = new CrossPattern(bulletManager);
	multiShotPattern = new MultiShotPattern(bulletManager);
	spiralPattern = new SpiralPattern(bulletManager);
	bouncePattern = new BouncePattern(bulletManager);
}

void GameScene::PatternDelete() {
	delete linePattern;
	delete twoCirclePattern;
	delete randomTopEdgePattern;
	delete zigzagRoadPattern;
	delete centerRotationPattern;
	delete halfPattern;
	delete nameHongPattern;
	delete nameGuakPattern;
	delete nameLeePattern;
	delete crossPattern;
	delete multiShotPattern;
	delete spiralPattern;
	delete bouncePattern;
}

void GameScene::OnBulletScreenOut() {
	BulletList::iterator iter;
	for (iter = bulletManager->bList.begin(); iter != bulletManager->bList.end(); iter++) {
		if ((*iter)->pos.x < -100 || (*iter)->pos.x > WIDTH + 116 || (*iter)->pos.y < -350 || (*iter)->pos.y > HEIGHT + 116) {
			(*iter)->isDelete = true;
		}
	}
}

void GameScene::CollisionCheck() {
	BulletList::iterator iter;
	for (iter = bulletManager->bList.begin(); iter != bulletManager->bList.end(); iter++) {
		if (GetDistance((*iter)->pos + D3DXVECTOR2((*iter)->sprite->width / 2, (*iter)->sprite->height / 2),
			player->pos + D3DXVECTOR2(player->spriteWhite->width / 2, player->spriteWhite->height / 2)) < 20) {
			if (player->isWhite != (*iter)->isWhite) {
				(*iter)->isDelete = true;
				player->isDelete = true;
			}
		}
	}
}

void GameScene::BounceCheck()
{
	BulletList::iterator iter;
	for (iter = bulletManager->bList.begin(); iter != bulletManager->bList.end(); iter++)
	{
		if ((*iter)->pos.x<=0)
		{
			(*iter)->dir = (*iter)->dir+45;
		}
		else if ((*iter)->pos.x + (*iter)->sprite->width >= WIDTH)
		{
			(*iter)->dir = (*iter)->dir - 45;
		}
		else if ((*iter)->pos.y <= 0)
		{
			(*iter)->dir = (*iter)->dir -45;
		}
		else if ((*iter)->pos.y + (*iter)->sprite->width >= HEIGHT)
		{
			(*iter)->dir = (*iter)->dir + 45;
		}
			
	}

}

void GameScene::SetPattern(float eTime) {
	
	if (isPatternDone) {
		if (isRandomPatternSet) {
			randomPatternSet++;
			dangerSignFirst->onActive = true;
			dangerSignFirst->patternNum = randomPatternSet;
			dangerSignSecond->onActive = true;
			dangerSignSecond->patternNum = randomPatternSet;
			isRandomPatternSet = false;
		}
		randomPattern = -1;
		patternBreakTimer->Update(eTime);
		if (patternBreakTimer->isDone) {
			randomPattern = randomPatternSet;
			isRandomPatternSet = true;
			isPatternDone = false;
			if (randomPatternSet >= 13) {
				isPatternDone = true;
				ChangeScene(new ClearScene());
				return;
			}
		}
	}

	switch (randomPattern) {
		case -1:
			break;
		case 0:
			linePattern->Update(eTime);
			break;
		case 1:
			twoCirclePattern->Update(eTime);
			break;
		case 2:
			randomTopEdgePattern->Update(eTime);
			break;
		case 3:
			zigzagRoadPattern->Update(eTime);
			break;
		case 4:
			centerRotationPattern->Update(eTime);
			break;
		case 5:
			halfPattern->Update(eTime);
			break;
		case 6:
			crossPattern->Update(eTime);
			break;
		case 7:
			multiShotPattern->Update(eTime);
			break;
		case 8:
			spiralPattern->Update(eTime);
			break;
		case 9:
			bouncePattern->Update(eTime);
			break;
		case 10:
			nameHongPattern->Update(eTime);
			break;
		case 11:
			nameGuakPattern->Update(eTime);
			break;
		case 12:
			nameLeePattern->Update(eTime);
			break;
	}
}