#pragma once
#include "Ksztalt.h"

class Kwadrat: public Ksztalt{
public:
    Kwadrat(int a): _a(a){}
    void wypisz(std::ostream& os) const override;
    double polePow() const override;
private:
    int _a;
};

void Kwadrat::wypisz(std::ostream& os) const{
    os << "Kwadrat o boku:" << _a << std::endl;
}

double Kwadrat::polePow() const{
    return _a * _a;
}