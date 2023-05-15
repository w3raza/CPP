#pragma once
#include "Operation.h"

class Division : public Operation{
public:
    Division(const double x, const double y): Operation(x,y) {}
    void print() const override;
    double eval() const override;

};