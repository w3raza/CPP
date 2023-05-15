#pragma once
#include "Wymierne.h"
#include <iostream>

class Double{
public:
    Double(double x): _x(x), _counter(0){}
    Double(const Wymierne& w);
    void print() const;
    double getx()const;
    void setx(const Double& d);

private:
    double _x;
    int _counter;
};

void print(const Double& d);