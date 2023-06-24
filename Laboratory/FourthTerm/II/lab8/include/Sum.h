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
    double value() const{}
    void operator()(double sum){}
};

Sum& sumData(const Data& d1){
    std::for_each(d._vec.)
    return Sum();
}

#endif