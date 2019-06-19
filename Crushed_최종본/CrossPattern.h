#pragma once;
#include "Pattern.h"
class CrossPattern :
	public Pattern
{
public:
	int cnt;

	CrossPattern(BulletManager *bulletManager);
	~CrossPattern();

	void Update(float eTime);
};