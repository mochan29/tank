#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Enemy.h"

class Tank;
class Enemy;
namespace
{
	int ENEMYNUM = 2;
}

class PlayScene :
	public GameObject
{
	Tank* player;
	int enemyNum_;
	Text* pText;

public:
	PlayScene(GameObject* parent) :GameObject(parent, "PlayScene"),player(nullptr),enemyNum_(2), pText(nullptr){};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override {};
	void DescEnemy() { enemyNum_--; }
	bool IsEnemyLeft() { return enemyNum_> 0; }
	int GetEnemyNum() { return enemyNum_; }

};

