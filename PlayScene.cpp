#include "PlayScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Tank.h"
#include "Ground.h"
#include "Enemy.h"

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	Camera::SetPosition({ 0,5,-10 });
	Camera::SetTarget({ 0,3,0 });
	for (int i = 0; i <enemyNum_; i++)
	{
		Enemy a=Instantiate<Enemy>(this);
		enemies.push_back(a);
	}
	pText = new Text;
	pText->Initialize();
	num_ = enemyNum_;
}

void PlayScene::Update()
{
	for (int i = 0; i < enemyNum_; i++)
	{
		if (enemies[i].zen_)
		{
			enemies.erase(enemies.begin());
		}
	}

	if (enemies.size()==0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}
