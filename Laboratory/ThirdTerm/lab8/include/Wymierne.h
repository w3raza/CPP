#pragma once
#include <iostream>

class Wymierne{
public:
    Wymierne(int licznik = 0, int mianownik = 1): _licznik(licznik), _mianownik(mianownik){}
    void print(const char* name) const;
    operator double();
    static Wymierne& pomnoz(const Wymierne& obj1, const Wymierne& obj2);
    int getLicznik()const;
    int getMianownik()const;
    void setM(int);
    
private:
    int _licznik;
    int _mianownik;
}; 

using wymierne = Wymierne;  // alias dla klasy Wymierne

Wymierne& pomnoz(const Wymierne& obj1, const Wymierne& obj2);