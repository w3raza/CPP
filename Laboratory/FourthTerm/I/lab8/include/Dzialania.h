#pragma once

#include "Wektor2D.h"
#include <algorithm>

class DzialaniaNaZbiorach{
public:
    DzialaniaNaZbiorach(std::set<Wektor2D> zbiorWektorw): _zbiorWektorw(zbiorWektorw){}

    void WypiszXWiekszeOd(int number)const;
    void ZamienX(int old_value, int new_value);
    void print(Wektor2D vec, int number) const;

private:
    std::set<Wektor2D> _zbiorWektorw;
};