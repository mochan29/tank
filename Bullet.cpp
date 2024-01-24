#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.3f);
	AddCollider(collision);
	playScene_ = (PlayScene*)GetParent();
}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	moveDir_ = { moveDir_.x,moveDir_.y -= 0.01,moveDir_.z };
	if (transform_.position_.y < -10)
		KillMe();
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		playScene_->DescEnemy();
		pTarget->KillMe();
	}
	this->KillMe();
}

