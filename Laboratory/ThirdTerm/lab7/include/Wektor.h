#pragma once
#include"Wymierne.h"
#include <iostream>

class Wektor{
public:
    Wektor() = default;
    Wektor(double number);
    Wektor& SetX(int licznik, int mianownik);
    Wektor& SetY(int licznik, int mianownik);
    Wektor& SetZ(int licznik, int mianownik);
    Wymierne& getX();
    void print() const;
private:
    Wymierne _x;
    Wymierne _y;
    Wymierne _z;
};