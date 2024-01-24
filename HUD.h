#pragma once
#include "Engine/GameObject.h"
#include "PlayScene.h"
#include <vector>

namespace
{
	const int DIGIT = 3;
}

class HUD :
	public GameObject
{

public:
	int hHUD_;
	int hNum_;
	Transform tHUD_;
	std::vector<Transform>tNum_;
	PlayScene* playScene_;
	HUD(GameObject* parent) :GameObject(parent, "HUD"),hHUD_(-1),hNum_(-1){};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override {};
};
