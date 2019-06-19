#pragma once
#include "Pattern.h"
class SpiralPattern :
	public Pattern
{
public:
	int cnt;
	int dir;
	int shot;

	SpiralPattern(BulletManager *bulletManager);
	~SpiralPattern();

	void Update(float eTime);
};