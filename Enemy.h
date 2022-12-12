#include "DxLib.h"
#include "stdio.h"
#include "Vector2.h"
#pragma once

class Enemy
{
public:
	static bool isAlive;

public:
	void Initialize(Vector2 pos);
	void Update();
	void Draw();

	void Kill();

private:
	Vector2 pos_;
	float r_;
};

