#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once
#include "shapes.h"

class Circle : public BasicShape{
private:
    unsigned _x;
    unsigned _y;
    unsigned _r;
public:
    Circle(unsigned x, unsigned y, unsigned r): _x(x), _y(y), _r(r){}
    Circle(const Point& p, unsigned r): _x(p.x()), _y(p.y()), _r(r){}
    double area() const override{ return 0;}
    bool isIn(unsigned x, unsigned y) const override{ return false;}
};

#endif