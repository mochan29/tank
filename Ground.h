#pragma once
#include "Engine/GameObject.h"
class Ground :
    public GameObject
{
	int hModel_;
public:
	Ground(GameObject* parent) :GameObject(parent, "Ground"), hModel_(-1){};
	~Ground() {};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override {};
	int GetModelHundle() { return hModel_; }
};

