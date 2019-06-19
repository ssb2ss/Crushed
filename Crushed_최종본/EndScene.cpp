#include "EndScene.h"
#include "myFunction.h"

EndScene::EndScene()
{
	background = new CSprite("images/gameover.png");
	restartButton = new CSprite("images/restartButton.png");
	restartButton->pos.x = WIDTH / 2 - restartButton->width / 2;
	restartButton->pos.y = 500;
}

EndScene::~EndScene()
{
	delete background;
	delete restartButton;
}


void EndScene::Update(float eTime) {
	background->Update(eTime);
	restartButton->Update(eTime);
	RestartButtonOpacitySet();
	OnClick();
}

void EndScene::Render() {
	background->Render(0);
	restartButton->Render(0);
}


void EndScene::RestartButtonOpacitySet() {
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

void EndScene::OnClick() {
	if (MyKeyState(VK_LBUTTON) == -1) {
		ChangeScene(new TitleScene());
	}
}