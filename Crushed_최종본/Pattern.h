#pragma once
#include "BulletManager.h"
#include "Timer.h"
class Pattern
{
public:
	BulletManager *bulletManager;
	Timer *timer;

	bool *isPatternDone;

	Pattern(BulletManager *bulletManager);
	virtual ~Pattern();

	virtual void Update(float eTime) = 0;
};

