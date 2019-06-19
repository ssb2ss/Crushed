#pragma once
#include "Pattern.h"
class CenterRotationPattern :
	public Pattern
{
public:
	int cnt;
	float dir;
	bool isRight;
	int plusSpeed;

	CenterRotationPattern(BulletManager *bulletManager);
	~CenterRotationPattern();

	void Update(float eTime);
};

