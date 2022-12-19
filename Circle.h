#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
	Circle(float radius);
	~Circle();

	void Size() override;
	void Draw() override;

private:
	float r_;
	const float PI_ = 3.14159265f;
	float area_;
};
