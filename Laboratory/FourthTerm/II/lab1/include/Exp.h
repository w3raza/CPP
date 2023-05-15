#pragma once
#include "Operation.h"
#include <cmath>

class Exponentiation : public Operation{
public:
    Exponentiation(const double x, const double y): Operation(x,y) {}
    void print() const override;
    double eval() const override;
};