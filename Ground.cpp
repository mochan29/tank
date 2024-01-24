#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"

void Ground::Initialize()
{
	hModel_ = Model::Load("Model\\Ground.fbx");
	assert(hModel_ >= 0);
	//transform_.position_ = { 0,-0.5,0 };
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
