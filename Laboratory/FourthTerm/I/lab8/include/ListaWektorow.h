#pragma once
#include "Wektor2D.h"
#include <vector>
#include <algorithm>
#include <iterator>

class ListaWektorow{
public:
    void Dodaj(Wektor2D* vec);
    void Wypisz()const;
    void PosortujWedlugX();
    void PosortujWedlugY();

private:
    std::vector<Wektor2D*> _list;    
};