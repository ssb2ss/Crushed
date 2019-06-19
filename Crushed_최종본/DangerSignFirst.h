#pragma once
#include "IObject.h"
#include "Sprite.h"
class DangerSignFirst :
	public IObject
{
public:
	int patternNum;

	bool onActive;
	bool isOpacUp;

	CSprite *sprite;

	DangerSignFirst();
	~DangerSignFirst();

	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);

	void PositionSet();
	void OpacitySet();
};

