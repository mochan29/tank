#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Enemy.h"
#include <vector>

class Tank;
class Enemy;


class PlayScene :
	public GameObject
{
	Tank* player;
	int enemyNum_;
	Text* pText;
	std::vector<Enemy> enemies;
	int num_;
public:
	PlayScene(GameObject* parent) :GameObject(parent, "PlayScene"),player(nullptr),enemyNum_(2), pText(nullptr){};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override {};
};

