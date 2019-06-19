#pragma once
#include "Pattern.h"
class BouncePattern :
	public Pattern
{
public:
	BouncePattern(BulletManager *bulletManager);
	~BouncePattern();

	void Update(float eTime);

	int cnt;

};

