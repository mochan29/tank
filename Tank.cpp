#include "Tank.h"
#include "TankHead.h"	
#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\tankbody.fbx");
	assert(hModel_ >= 0);
	Instantiate<TankHead>(this);

	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.6f);
	AddCollider(collision);
}

void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();
	XMVECTOR move{ 0,0,0,0 };
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 1;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;
	}
	if (Input::IsKey(DIK_W))
	{
		dir =1.0;
	}
	if (Input::IsKey(DIK_S))
	{
		dir =-1.0;
	}
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	rotVec = XMVector3TransformCoord(front_, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos =pos+dir* move;
	XMStoreFloat3(&(transform_.position_), pos);

	Ground* pGround=(Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHundle();
	RayCastData data;
	data.start=transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3{ 0,-1,0 };
	Model::RayCast(hGmodel, &data);

	if (data.hit)
	{
		transform_.position_.y=-data.dist+1.0f;
	}

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		if (camState_ == CAM_TYPE::MAX)
		{
			camState_ = CAM_TYPE::FIX;
		}
	}

	switch (camState_)
	{
	case FIX:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case TPS_NOROT:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y += 15.0f;
		camPos.z -= 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case TPS:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case FPS:
	{
		Camera::SetPosition(transform_.position_);
		XMFLOAT3 camTarget;
		XMStoreFloat3(&camTarget, pos +move);
		Camera::SetTarget(camTarget);
		break;
	}
	default:
		break;
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
