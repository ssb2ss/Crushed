#pragma once
#include "Pattern.h"
class ZigzagRoadPattern :
	public Pattern
{
public:
	int cnt;
	float std;
	float speed;
	bool isLeft;

	ZigzagRoadPattern(BulletManager *bulletManager);
	~ZigzagRoadPattern();

	void Update(float eTIme);
};

