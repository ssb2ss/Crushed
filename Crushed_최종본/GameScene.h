#pragma once
#include "IScene.h"
#include "Player.h"
#include "BulletManager.h"
#include "Timer.h"
#include "EndScene.h"
#include "DangerSignFirst.h"
#include "DangerSignSecond.h"
#include "LinePattern.h"
#include "TwoCirclePattern.h"
#include "RandomTopEdgePattern.h"
#include "ZigzagRoadPattern.h"
#include "CenterRotationPattern.h"
#include "HalfPattern.h"
#include "NameHongPattern.h"
#include "NameGuakPattern.h"
#include "NameLeePattern.h"
#include "CrossPattern.h"
#include "MultiShotPattern.h"
#include "SpiralPattern.h"
#include "ClearScene.h"
#include "BouncePattern.h"

class GameScene :
	public IScene
{
public:
	bool isRandomPatternSet;
	int randomPatternSet;
	int randomPattern;

	static bool isPatternDone;

	Player *player;
	BulletManager *bulletManager;

	CSprite *background;

	Timer *patternBreakTimer;

	DangerSignFirst *dangerSignFirst;
	DangerSignSecond *dangerSignSecond;

	NameHongPattern *nameHongPattern;
	NameGuakPattern *nameGuakPattern;
	NameLeePattern *nameLeePattern;
	LinePattern *linePattern;
	TwoCirclePattern *twoCirclePattern;
	RandomTopEdgePattern *randomTopEdgePattern;
	ZigzagRoadPattern *zigzagRoadPattern;
	CenterRotationPattern *centerRotationPattern;
	HalfPattern *halfPattern;
	CrossPattern *crossPattern;
	MultiShotPattern *multiShotPattern;
	SpiralPattern *spiralPattern;
	BouncePattern *bouncePattern;

	GameScene();
	~GameScene();

	void PatternDefine();
	void PatternDelete();

	void Update(float eTime);
	void Render();

	void OnBulletScreenOut();
	void CollisionCheck();
	void SetPattern(float eTime);

	void BounceCheck();
};