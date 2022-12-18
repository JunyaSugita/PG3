#include "DxLib.h"
#include "stdio.h"
#include "Vector2.h"
#include "Bullet.h"
#pragma once

enum class PHASE
{
	APPROACH,
	SHOT,
	SECESSION,
};

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
	static void (Enemy::* pFunc[])();


private:
	Vector2 pos_;
	float r_;
	float speed_;
	bool isDead_;
	PHASE phase_;
};

