#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "PlayScene.h"

class Playscene;

class Enemy :
    public GameObject
{
	int hModel_;
	Text* pText;

public:
	Enemy(GameObject* parent) :GameObject(parent, "Enemy"), hModel_(-1), pText(nullptr),zen_(false){};
	~Enemy() {};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override {};
	void OnCollision(GameObject* pTarget) override;
	bool zen_;
};

 