#ifndef SHAPE_H
#define SHAPE_H

#pragma once
#include <iostream>
#include <memory>
#include <cmath>

enum ShapeOperation{
    SUM,
    INTERSECTION,
    DIFFERENCE,
};

class Point{
private:
    unsigned _x;
    unsigned _y;
public:
    Point(unsigned x, unsigned y): _x(x), _y(y){}
    unsigned x() const {return _x;}
    unsigned y() const {return _y;}
};


class Shape{
public:
    virtual ~Shape() = default;
    virtual bool isIn(unsigned x, unsigned y) const = 0;
};

class BasicShape : virtual public Shape{
public:
    virtual ~BasicShape() = default;
    virtual double area() const = 0;
};

class HasDiagonal : virtual public Shape{
public:
    virtual ~HasDiagonal() = default;
    virtual double diagonal() const = 0;
};

void printShape(const Shape& shape, unsigned x, unsigned y){

}

#endif