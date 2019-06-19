#include "TitleScene.h"
#include "SoundMgr.h"

extern SoundMgr *soundMgr;

TitleScene::TitleScene()
{
	title = new CSprite("images/title.png");
	startButton = new CSprite("images/startButton.png");
	startButton->pos.x = WIDTH / 2 - startButton->width / 2;
	startButton->pos.y = 500;
	title->opacity = 0;

	isOpacUp = false;
	bgOpacUp = true;

}

TitleScene::~TitleScene()
{
	delete title;
	delete startButton;
}


void TitleScene::Update(float eTime) {
	title->Update(eTime);
	startButton->Update(eTime);
	StartButtonOpacitySet();
	BGOpecitySet();
	OnClick();
}

void TitleScene::Render() {
	title->Render(0);
	startButton->Render(0);
}


void TitleScene::StartButtonOpacitySet() {
	if (isOpacUp) {
		startButton->opacity += 4;
		if (startButton->opacity >= 255) {
			startButton->opacity = 255;
			isOpacUp = false;
		}
	}
	else {
		startButton->opacity -= 4;
		if (startButton->opacity <= 0) {
			startButton->opacity = 0;
			isOpacUp = true;
		}
	}
}

void TitleScene::BGOpecitySet() {
	if (bgOpacUp) {
		title->opacity += 4;
		if (title->opacity >= 255) {
			title->opacity = 255;
			bgOpacUp = false;
		}
	}
}

void TitleScene::OnClick() {
	if (MyKeyState(VK_LBUTTON) == -1) {
		ChangeScene(new GameScene());
	}
}