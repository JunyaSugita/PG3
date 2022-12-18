#include "Enemy.h"
#include "time.h"

void (Enemy::* Enemy::pFunc[])() = {
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::Secession,
};


void Enemy::Initialize(Vector2 pos)
{
	pos_ = pos;
	isDead_ = false;
	r_ = 12;
	speed_ = 2;
	phase_ = PHASE::APPROACH;
}

void Enemy::Update()
{
	(this->*pFunc[static_cast<size_t>(phase_)])();
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
		phase_ = PHASE::SHOT;
	}
}

void Enemy::Shot()
{
	bullet.Initialize(pos_);
	phase_ = PHASE::SECESSION;
}

void Enemy::Secession()
{
	pos_.y--;
	if (pos_.y < 100) {
		phase_ = PHASE::APPROACH;
	}
}
