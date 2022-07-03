
//
// Przyk�adowy kod z rozdzia�u 5.10.1 "Warunki ko�cowe" ksi��ki
// "Programming -- Principles and Practice Using C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Bad_area { };    // Specjalny typ do raportowania b��d�w w funkcji area().

// Oblicza pole powierzchni prostok�ta.
// Zg�asza wyj�tek Bad_area, gdy pojawi si� nieprawid�owy argument.
int area1(int length, int width)
{
    if (length<=0 || width <=0) throw Bad_area();
    return length*width;
}

//------------------------------------------------------------------------------

int area(int length, int width)
// Oblicza pole powierzchni prostok�ta.
// Warunki wst�pne: length i width maj� warto�ci dodatnie.
// Warunek ko�cowy: zwraca dodatni� warto�� wyznaczaj�c� pole powierzchni.
{
    if (length<=0 || width <=0) error("Warunek wst�pny funkcji area().");
    int a =  length*width;
    if (a<=0) error("Warunek ko�cowy funkcji area().");
    return a;
}

//------------------------------------------------------------------------------

int main()
try
{
    area(2000000000, 2000000000);
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
