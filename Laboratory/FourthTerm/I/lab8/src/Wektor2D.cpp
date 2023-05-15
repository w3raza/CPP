#include "Wektor2D.h"

int Wektor2D::getX()const{ return _x;}
int Wektor2D::getY()const{ return _y;}

void Wektor2D::print()const{
    std::cout << _length << "(" << _x << ", " << _y << ")";
}

bool Wektor2D::operator<(Wektor2D& vec){
    return _x < vec._x;
}

std::ostream& operator<<(std::ostream& os, Wektor2D* vec){
    vec->print();
    return os;
}
