#pragma once
#include "Engine/GameObject.h"

class TankHead:
    public GameObject
{
    int hModel_;
public:
    TankHead(GameObject* parent) :GameObject(parent, "TankHead"), hModel_(-1) {};
    ~TankHead() {};
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override {};
    int GetModelHandle() { return hModel_; }
};

