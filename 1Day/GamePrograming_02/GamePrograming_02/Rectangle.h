#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
private:
    int width, height;
public:
    void setWidth(int);
    void setHeight(int);

    void scale();
};

