#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"

void HUD::Initialize()
{
	hHUD_ = Image::Load("Image\\nokori.png");
	hNum_ = Image::Load("Image\\number.png");
	assert(hHUD_>= 0);
	assert(hNum_ >= 0);
	for (int i = 0; i < 3; i++)
	{
		Transform t;
		t.position_ = { 6 + 50 * i,0,0 };
		tNum_.push_back(t);
	}
}

void HUD::Update()
{
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHUD_);
	Image::Draw(hHUD_);

}
