#include "Operation.h"

const double Operation::getX()const{
    return _x;
}

const double Operation::getY()const{
    return _y;
}

void operator>>=(const char* name, const Operation& d){
    std::cout << name << "\t";
    d.print();
    std::cout << std::endl;
}