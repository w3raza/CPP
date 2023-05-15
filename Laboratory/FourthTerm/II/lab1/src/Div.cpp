#include "Div.h"

void Division::print() const{
    std::cout << getX() << " / " << getY();
}

double Division::eval() const{
    return getX() / getY();
}