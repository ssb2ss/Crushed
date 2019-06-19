#pragma once
#include "Pattern.h"
class HalfPattern :
	public Pattern
{
public:
	int cnt;

	HalfPattern(BulletManager *bulletManager);
	~HalfPattern();

	void Update(float eTime);
};

