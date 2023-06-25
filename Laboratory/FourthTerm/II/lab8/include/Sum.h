#ifndef SUM_H
#define SUM_H

#pragma once
#include "Data.h"
#include <iostream>

class Sum{
private:
    double _sum;
public:
    Sum(double sum): _sum(sum){}
    double value() const{ return _sum;}
    void operator()(double sum){ _sum += sum;}
};

Sum sumData(const Data& d1){
    double s = d1.sum();
    return Sum(s);
}

#endif