#pragma once
#include "Operation.h"

class Addition : public Operation{
public:
    Addition(const double x, const double y): Operation(x,y)  {}
    void print() const override;
    double eval() const override;
};