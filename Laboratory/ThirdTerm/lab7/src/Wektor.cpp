#include"Wektor.h"

Wektor::Wektor(double number){
    SetX(number, 1);
    SetY(number, 1);
    SetZ(number, 1);
}

Wektor& Wektor::SetX(int licznik, int mianownik){
    _x = Wymierne(licznik, mianownik);

    return *this;
}

Wektor& Wektor::SetY(int licznik, int mianownik){
    _y = Wymierne(licznik, mianownik);

    return *this;
}

Wektor& Wektor::SetZ(int licznik, int mianownik){
    _z = Wymierne(licznik, mianownik);

    return *this;
}

Wymierne& Wektor::getX(){
    return _x;
}

void Wektor::print() const{
    std::cout << "[";
    _x.print();
    std::cout << ", ";
    _y.print();
    std::cout << ", ";
    _z.print();
    std::cout << "]";
    std::cout << std::endl;
}