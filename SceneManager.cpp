#include "SceneManager.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}

SceneManager* SceneManager::GetInstans()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeNextScene(int nextScene)
{
	scene_ = nextScene;
}

void SceneManager::DrawScene()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "gameScene = ");

	switch (scene_)
	{
	case Title:
		DrawFormatString(120, 0, GetColor(255, 255, 255), "Title");
		break;
	case NewGame:
		DrawFormatString(120, 0, GetColor(255, 255, 255), "NewGame");
		break;
	case GamePlay:
		DrawFormatString(120, 0, GetColor(255, 255, 255), "GamePlay");
		break;
	case GameClear:
		DrawFormatString(120, 0, GetColor(255, 255, 255), "GameClear");
		break;

	default:
		break;
	}
}
