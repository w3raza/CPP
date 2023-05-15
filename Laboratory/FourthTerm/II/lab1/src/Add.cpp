#include "Add.h"

void Addition::print() const{
    std::cout << getX() << " + " << getY();
}

double Addition::eval() const{
    return getX() + getY();
}