#pragma once
#include "Ksztalt.h"
#include <cmath>

class Kolo: public Ksztalt{
public:
    Kolo(int r): _r(r){}
    void wypisz(std::ostream& os) const override;
    double polePow() const override;
private:
    int _r;
};

void Kolo::wypisz(std::ostream& os) const{
    os << "Kolo o promieniu:" << _r << std::endl;
}

double Kolo::polePow() const{
    return std::pow(_r,2) * M_PI;
}