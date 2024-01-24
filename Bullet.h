#pragma once
#include "Engine/GameObject.h"
#include "PlayScene.h"

class Bullet :
	public GameObject
{
	int hModel_;
	float bulletSpeed_;
	XMFLOAT3 moveDir_;
	PlayScene* playScene_;
public:
	Bullet(GameObject* parent) :GameObject(parent, "Bullet"), hModel_(-1) ,bulletSpeed_(0),moveDir_(0,0,0){};
	~Bullet() {};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override {};
	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move;}
	void SetSpeed(float _speed) { bulletSpeed_ = _speed; }
	void OnCollision(GameObject* pTarget) override;
};

