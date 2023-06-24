#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once
#include "shapes.h"

class Rectangle : public HasDiagonal, public BasicShape{
private:
    unsigned _xFrom;
    unsigned _xTo;
    unsigned _yFrom;
    unsigned _yTo;
public:
    Rectangle(unsigned xFrom, unsigned yFrom, unsigned xTo, unsigned yTo): _xFrom(xFrom), _yFrom(yFrom), _xTo(xTo), _yTo(yTo){}
    Rectangle(const Point& from, const Point& to): _xFrom(from.x()), _yFrom(from.y()), _xTo(to.x()), _yTo(to.y()){}
    double area() const override{ return 0;}
    double diagonal() const override{return 0;}
    bool isIn(unsigned x, unsigned y) const override{ return false;}
};

#endif