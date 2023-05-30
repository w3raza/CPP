#include "Wektor2D.h"

int Wektor2D::getX()const{ return _x;}
int Wektor2D::getY()const{ return _y;}
std::string Wektor2D::getName()const{ return _name;}

void Wektor2D::print()const{
    std::cout << _name << " (" << _x << ", " << _y << ")" << std::endl;
}

bool Wektor2D::operator<(const Wektor2D& vec)const{
    return _x < vec._x;
}

std::ostream& operator<<(std::ostream& os, Wektor2D* vec){
    vec->print();
    return os;
}
