#include "Pattern.h"

Pattern::Pattern(BulletManager *bulletManager)
{
	this->bulletManager = bulletManager;
}

Pattern::~Pattern()
{
	delete timer;
}