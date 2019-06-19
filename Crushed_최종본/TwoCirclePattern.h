#pragma once
#include "Pattern.h"
class TwoCirclePattern :
	public Pattern
{
public:
	int cnt;

	TwoCirclePattern(BulletManager *bulletManager);
	~TwoCirclePattern();

	void Update(float eTime);
};

