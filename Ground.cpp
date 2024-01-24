#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"

void Ground::Initialize()
{
	hModel_ = Model::Load("Model\\Ground.fbx");
	assert(hModel_ >= 0);
	transform_.position_.y -= 0.5;
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
