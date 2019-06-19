#pragma once
#include "Pattern.h"
class LinePattern :
	public Pattern
{
public:
	int cnt;

	LinePattern(BulletManager *bulletManager);
	~LinePattern();

	void Update(float eTime);
};

