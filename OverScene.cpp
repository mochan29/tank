#include "OverScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

void OverScene::Initialize()
{
	hImage_ = Image::Load("Image\\clear.png");
	assert(hImage_ >= 0);
}

void OverScene::Draw()
{
	Image::Draw(hImage_);
}

