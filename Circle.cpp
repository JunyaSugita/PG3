#include "Circle.h"
#include <stdio.h>

Circle::Circle(float radius)
{
	r_ = radius;
	area_ = 0.0f;
}

Circle::~Circle()
{
}

void Circle::Size()
{
	area_ = r_ * PI_;
}

void Circle::Draw()
{
	printf("ñ êœ: %f\n", area_);
}
