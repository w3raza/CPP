#include "ListaWektorow.h"

void ListaWektorow::Dodaj(Wektor2D* vec){
    _list.push_back(vec);
}

void ListaWektorow::Wypisz()const{
    std::for_each(_list.begin(), _list.end(), [](Wektor2D* vec) -> void {std::cout << vec << std::endl;});
}

void ListaWektorow::PosortujWedlugX(){
    std::cout << "Posortowana wedlug wsprzednych X" << std::endl;
    std::sort(_list.begin(), _list.end(), [](Wektor2D* vec, Wektor2D* vec2) {return vec->getX() < vec2->getX();});
}

void ListaWektorow::PosortujWedlugY(){
    std::cout << "Posortowana wedlug wsprzednych Y" << std::endl;
    std::sort(_list.begin(), _list.end(), [](Wektor2D* vec, Wektor2D* vec2) {return vec->getY() < vec2->getY();});
}

