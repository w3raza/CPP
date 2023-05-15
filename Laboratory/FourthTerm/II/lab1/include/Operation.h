#pragma once
#include <iostream>

class Operation{
public:
    Operation(const double x, const double y): _x(x), _y(y) {}
    virtual ~Operation(){}
    const double getX()const; 
    const double getY()const; 
    virtual void print() const = 0;
    virtual double eval() const = 0;

private:
    const double _x;
    const double _y;
};

void operator>>=(const char* name, const Operation& d);