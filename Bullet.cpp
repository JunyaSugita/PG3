#include "Bullet.h"

void Bullet::Initialize(Vector2 pos)
{
	pos_ = pos;
	speed_ = 3;
	r_ = 5;
	isDead_ = false;
}

void Bullet::Update()
{
	if (isDead_ == false) {
		pos_.y += speed_;
	}
}

void Bullet::Draw()
{
	if (isDead_ == false) {
		DrawCircle(pos_.x, pos_.y, r_, GetColor(200, 0, 0), true);
	}
}
