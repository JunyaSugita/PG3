#include "Rectangle.h"
#include <stdio.h>

Rectangle::Rectangle(float x,float y)
{
	x_ = x;
	y_ = y;
	area_ = 0;
}

Rectangle::~Rectangle()
{
}

void Rectangle::Size()
{
	area_ = x_ * y_;
}

void Rectangle::Draw()
{
	printf("ñ êœ: %f\n", area_);
}
