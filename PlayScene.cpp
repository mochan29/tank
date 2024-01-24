#include "PlayScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Tank.h"
#include "Ground.h"
#include "Enemy.h"
#include "HUD.h"

void PlayScene::Initialize()
{
	enemyNum_ = ENEMYNUM;
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	for (int i = 0; i <enemyNum_; i++)
	{
		Instantiate<Enemy>(this);
	}
	Instantiate<HUD>(this);
}

void PlayScene::Update()
{
	if (enemyNum_ <= 0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}
