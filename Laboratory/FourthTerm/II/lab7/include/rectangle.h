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
    double area() const override{ return calculateTheLengthX() * calculateTheLengthY();}
    double diagonal() const override{return sqrt(pow(calculateTheLengthX(),2) + pow(calculateTheLengthY(),2));}
    bool isIn(unsigned x, unsigned y) const override{ 
        if((_xFrom <= x && x <= _xTo) && (_yFrom <= y && y <= _yTo))
            return true;
        else
            return false;
    }
    unsigned calculateTheLengthX() const{ return (_xTo - _xFrom);}
    unsigned calculateTheLengthY() const{ return (_yTo - _yFrom);}
    void print(std::ostream& os) const override{
        int x = calculateTheLengthX();
        int y = calculateTheLengthY();
        for(int i = 0; i < x; i++){
            os << (x - i - 1) << ":      ";
            for(int j = 0; j < y; j++){
                os << "*";
            }
            os << std::endl;
        }
    }
};

#endif