#pragma once
#include "IObject.h"
#include "Sprite.h"
class DangerSignSecond :
	public IObject
{
public:
	int patternNum;

	bool onActive;
	bool isOpacUp;

	CSprite *sprite;

	DangerSignSecond();
	~DangerSignSecond();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void PositionSet();
	void OpacitySet();
};

