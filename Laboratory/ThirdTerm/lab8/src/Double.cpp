#include "Double.h"

void print(const Double& d){
    d.print();    
}

Double::Double(const Wymierne& w){
    _x = ((double)w.getLicznik()/(double)w.getMianownik());
}

void Double::print() const{
    const_cast<int&>(_counter) += 1;
    std::cout << "Print nr " << _counter << ". Val = " << _x << std::endl;
}

double Double::getx()const{
    return _x;
}

void Double::setx(const Double& d){
    _x = d._x;
}