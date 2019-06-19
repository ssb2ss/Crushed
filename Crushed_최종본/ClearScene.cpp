#include "ClearScene.h"
#include "myFunction.h"

ClearScene::ClearScene()
{
	background = new CSprite("images/gameclear.png");
	restartButton = new CSprite("images/restartButton.png");
	restartButton->pos.x = WIDTH / 2 - restartButton->width / 2;
	restartButton->pos.y = 500;
}

ClearScene::~ClearScene()
{
	delete background;
	delete restartButton;
}


void ClearScene::Update(float eTime) {
	background->Update(eTime);
	restartButton->Update(eTime);
	RestartButtonOpacitySet();
	OnClick();
}

void ClearScene::Render() {
	background->Render(0);
	restartButton->Render(0);
}


void ClearScene::RestartButtonOpacitySet() {
	if (isOpacUp) {
		restartButton->opacity += 4;
		if (restartButton->opacity >= 255) {
			restartButton->opacity = 255;
			isOpacUp = false;
		}
	}
	else {
		restartButton->opacity -= 4;
		if (restartButton->opacity <= 0) {
			restartButton->opacity = 0;
			isOpacUp = true;
		}
	}
}

void ClearScene::OnClick() {
	if (MyKeyState(VK_LBUTTON) == -1) {
		ChangeScene(new TitleScene());
	}
}