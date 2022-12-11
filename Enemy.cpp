#include "Enemy.h"
#include "time.h"

bool Enemy::isDead;

void Enemy::Initialize(Vector2 pos)
{
	pos_ = pos;
	isDead = false;
	r_ = 12;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	if (isDead == false) {
		DrawCircle(pos_.x, pos_.y, r_, GetColor(200, 0, 0), true);
	}
}

void Enemy::Kill()
{
	isDead = true;
}
