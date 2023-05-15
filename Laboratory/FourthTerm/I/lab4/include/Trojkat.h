#pragma once
#include "Ksztalt.h"
#include <cmath>

class Trojkat: public Ksztalt{
public:
    Trojkat(int a, int b, int c): _a(a), _b(b), _c(c){}
    void wypisz(std::ostream& os) const override;
    double polePow() const override;
private:
    int _a;
    int _b;
    int _c;
};

void Trojkat::wypisz(std::ostream& os) const{
    os << "Trojkat bokach:" << _a << " " << _b << " " << _c << std::endl;
}

double Trojkat::polePow() const{
    double x = (double)(_a + _b + _c)/2;
    return std::sqrt(x * (x - _a) * (x - _b) * (x - _c));
}