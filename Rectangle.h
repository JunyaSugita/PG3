#pragma once
#include "IShape.h"

class Rectangle : public IShape
{
public:
	Rectangle(float x,float y);
	~Rectangle();

	void Size() override;
	void Draw() override;

private:
	float x_;
	float y_;
	float area_;
};

