#include "Dzialania.h"

void DzialaniaNaZbiorach::WypiszXWiekszeOd(int number)const{
    std::for_each(_zbiorWektorw.begin(), _zbiorWektorw.end(), [&](const Wektor2D& vec) {
    if (vec.getX() >= number) {
        vec.print();
    }
    });
}

void DzialaniaNaZbiorach::ZamienX(int old_value, int new_value){
    auto vec = _zbiorWektorw.find({"", old_value, 0});
    _zbiorWektorw.insert(Wektor2D (vec->getName(), new_value, vec->getY()));
    _zbiorWektorw.erase(vec);
}