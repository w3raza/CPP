#pragma once
#include <iostream>

class Ksztalt{
public:
    Ksztalt(){}
    virtual void wypisz(std::ostream& os) const = 0;
    virtual double polePow() const = 0;
};

void wypisz(const Ksztalt &obj){
    obj.wypisz(std::cout);
}