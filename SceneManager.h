#include "DxLib.h"
#pragma once

enum SCENE
{
	Title,
	NewGame,
	GamePlay,
	GameClear
};

class SceneManager final
{
private:
	SceneManager();
	~SceneManager();

public:
	SceneManager(const SceneManager& obj) = delete;
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstans();

	void ChangeNextScene(int nextScene);
	void DrawScene();

	int GetScene() {
		return scene_;
	}

private:
	int scene_ = Title;
};
