#include "Exp.h"

void Exponentiation::print() const{
    std::cout << getX() << " ^ " << getY();
}

double Exponentiation::eval() const{
    return std::pow(getX(), getY());
}