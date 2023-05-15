#pragma once
#include <iostream>

class Wymierne{
public:
    Wymierne() = default;
    Wymierne(int licznik, int mianownik): _licznik(licznik), _mianownik(mianownik){}
    void print() const;
    operator double();
    static double ToDouble(Wymierne& obj);
private:
    int _licznik;
    int _mianownik;
};