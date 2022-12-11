#include "DxLib.h"
#include "Vector2.h"
#pragma once

class Bullet
{
public:
	void Initialize(Vector2 pos);
	void Update();
	void Draw();

private:
	Vector2 pos_;
	float speed_;
	float r_;
	bool isDead_;
};

