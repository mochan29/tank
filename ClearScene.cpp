#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

void ClearScene::Initialize()
{
	hImage_ = Image::Load("Image\\clear.png");
	assert(hImage_ >= 0);
}

void ClearScene::Draw()
{
	Image::Draw(hImage_);
}

