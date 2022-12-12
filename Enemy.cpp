#include "Enemy.h"
#include "time.h"

bool Enemy::isAlive;

void Enemy::Initialize(Vector2 pos)
{
	pos_ = pos;
	isAlive = true;
	r_ = 12;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	if (isAlive == true) {
		DrawCircle(pos_.x, pos_.y, r_, GetColor(200, 0, 0), true);
	}
}

void Enemy::Kill()
{
	isAlive = false;
}
