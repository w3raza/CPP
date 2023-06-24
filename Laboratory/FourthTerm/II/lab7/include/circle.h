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
    double area() const override{ return M_PI * pow(_r, 2);}
    bool isIn(unsigned x, unsigned y) const override{ 
        if(((_x - _r) <= x && x <= (_x + _r)) && ((_y - _r) <= y && y <= (_y + _r)))
            return true;
        else
            return false;
    }
    void print(std::ostream& os) const override{
        
    }
};

#endif