#pragma once
#include "Engine/GameObject.h"

enum CAM_TYPE
{
	//固定、三人称回転なし、三人称、一人称、チェック用
	FIX, TPS_NOROT, TPS, FPS, MAX,
};

class Tank:
    public GameObject
{
	int hModel_;
	XMVECTOR front_;
	XMVECTOR moved_;
	float speed_;
	int camState_;
public:
	Tank(GameObject* parent) :GameObject(parent, "Tank"), hModel_(-1), speed_(0.05), front_({0,0,1,0}),camState_(FIX) {};
	~Tank() {};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override {};
};

