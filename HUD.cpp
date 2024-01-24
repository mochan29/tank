#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"

void HUD::Initialize()
{
	hHUD_ = Image::Load("Image\\nokori.png");
	hNum_ = Image::Load("Image\\number.png");
	assert(hHUD_>= 0);
	assert(hNum_ >= 0);

	//ŽOŒ…•À‚×‚Ä‚é
	for (int i = 0; i < DIGIT; i++)
	{
		Transform tN;
		tN.position_ = { float(-0.70 + 0.03 * i),0.90,0 };
		tNum_.push_back(tN);
	}
	playScene_ = (PlayScene*)GetParent();
}

void HUD::Update()
{
	tHUD_.position_ = { -0.73,0.90,0 };
	tHUD_.scale_ = { 0.7,0.7,1.0 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHUD_);
	Image::Draw(hHUD_);

	Image::SetRect(hNum_, 6 + 9 * 50, 0, 50, 64);
	for (int i = 0; i < DIGIT; i++)
	{
		Image::SetTransform(hNum_, tNum_[i]);
		tNum_[i].scale_ = {0.4,0.4,1.0};
		Image::Draw(hNum_);
	}
}
