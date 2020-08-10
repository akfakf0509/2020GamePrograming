#pragma once
#include <iostream>
class Shape
{
protected:
	int x, y;
public:
	void setOrigin(int, int);
	virtual void draw();
	virtual void scale() = 0;
};

