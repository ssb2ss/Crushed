#pragma once
#include "Pattern.h"
class RandomTopEdgePattern :
	public Pattern
{
public:
	int cnt;

	RandomTopEdgePattern(BulletManager *bulletManager);
	~RandomTopEdgePattern();

	void Update(float eTime);
};

