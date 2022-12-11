#include "DxLib.h"
#include "stdio.h"
#include "Vector2.h"
#include "Bullet.h"
#pragma once

class Enemy
{
public:
	void Initialize(Vector2 pos);
	void Update();
	void Draw();

	void Kill();

	void Approach();
	void Shot();
	void Secession();

	Bullet bullet;

private:
	void (Enemy::* pFunc)();

private:
	Vector2 pos_;
	float r_;
	float speed_;
	bool isDead_;
};

