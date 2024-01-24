#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"
#include <string>



void HUD::Initialize()
{
	hHUD_ = Image::Load("Image\\noko.png");
	hNum_ = Image::Load("Image\\number.png");
	assert(hHUD_>= 0);
	assert(hNum_ >= 0);
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
	int eneNum=playScene_->GetEnemyNum();
	if (eneNum >= 100)
	{
		std::string s = std::to_string(eneNum);
		for (int i = 0; i < DIGIT; i++)
		{
			digit[i] = int(s[i] - '0');
		}
	}
	else if (eneNum <= 99 && eneNum >= 10)
	{
		digit[0] = 0;
		std::string s = std::to_string(eneNum);
		digit[1]= int(s[0] - '0');
		digit[2] = int(s[1] - '0');

	}
	else
	{
		digit[0] = 0;
		digit[1] = 0;
		digit[2] = eneNum;
	}
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHUD_);
	Image::Draw(hHUD_);

	for (int i = 0; i < DIGIT; i++)
	{
		Image::SetRect(hNum_, 6 + digit[i] * 50, 0, 50, 64);
		Image::SetTransform(hNum_, tNum_[i]);
		tNum_[i].scale_ = {0.4,0.4,1.0};
		Image::Draw(hNum_);
	}
}
