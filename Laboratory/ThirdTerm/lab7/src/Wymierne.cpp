#include"Wymierne.h"

void Wymierne::print() const{
    if(_mianownik != 1)
        std::cout << _licznik << "/" << _mianownik;
    else
        std::cout << _licznik;
}

Wymierne::operator double(){
    return (double)_licznik/(double)_mianownik;
}

double Wymierne::ToDouble(Wymierne& obj){
    return (double)obj._licznik/(double)obj._mianownik;
}