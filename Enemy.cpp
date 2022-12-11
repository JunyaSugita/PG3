#include "Enemy.h"
#include "time.h"

void Enemy::Initialize(Vector2 pos)
{
	pos_ = pos;
	isDead_ = false;
	r_ = 12;
	speed_ = 2;
	pFunc = &Enemy::Approach;
}

void Enemy::Update()
{
	(this->*pFunc)();
	bullet.Update();
}

void Enemy::Draw()
{
	if (isDead_ == false) {
		DrawCircle(pos_.x, pos_.y, r_, GetColor(200, 0, 0), true);
	}
	bullet.Draw();
}

void Enemy::Kill()
{
	isDead_ = true;
}

void Enemy::Approach()
{
	pos_.y += speed_;
	if (pos_.y > 300) {
		pFunc = &Enemy::Shot;
	}
}

void Enemy::Shot()
{
	bullet.Initialize(pos_);
	pFunc = &Enemy::Secession;
}

void Enemy::Secession()
{
	pos_.y--;
	if (pos_.y < 100) {
		pFunc = &Enemy::Approach;
	}
}
