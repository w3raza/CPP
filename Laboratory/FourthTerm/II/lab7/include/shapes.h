#ifndef SHAPE_H
#define SHAPE_H

#pragma once
#include <iostream>
#include <memory>
#include <cmath>

#ifndef M_PI
    constexpr double M_PI = 3.1415926;
#endif

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
    virtual void print(std::ostream& os) const = 0;
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

#endif