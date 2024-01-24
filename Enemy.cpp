#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Model.h"
#include "Engine/SceneManager.h"
#include "Ground.h"
#include "PlayScene.h"

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\enemy.fbx");
	Model::SetAnimFrame(hModel_, 0, 60,1);
	assert(hModel_ >= 0);

	float x = (float)rand() / RAND_MAX;
	x = 2.0 * x;
	transform_.position_.x = 25.0 * (x - 1.0);
	transform_.position_.y = 1.0;
	float z = (float)rand() / RAND_MAX;
	z = 2.0 * z;
	transform_.position_.z = 25.0 * (z - 1.0);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHundle();
	RayCastData data;
	data.start = transform_.position_;
	data.dir = XMFLOAT3{ 0,-1,0 };
	Model::RayCast(hGmodel, &data);
	if (data.hit)
	{
		transform_.position_.y = -data.dist+1.0f;
	}

	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.6f);
	AddCollider(collision);
	pText = new Text;
	pText->Initialize();
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	pText->Draw(30, 30, "LEFT");
	//pText->Draw(30, 60, );
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		this->KillMe();
		pTarget->KillMe();		
		this->zen_ = true;
	}

	if (pTarget->GetObjectName() == "Tank" || pTarget->GetObjectName() == "TankHead")
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_OVER);
	}
}


