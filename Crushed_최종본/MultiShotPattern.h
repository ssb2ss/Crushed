#pragma once
#include "Pattern.h"
class MultiShotPattern :
	public Pattern
{
public:
	int cnt;
	int dir;
	int shot;

	MultiShotPattern(BulletManager *bulletManager);
	~MultiShotPattern();

	void Update(float eTime);
};