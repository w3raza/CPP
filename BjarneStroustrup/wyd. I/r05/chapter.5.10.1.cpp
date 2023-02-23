
//
// Przyk³adowy kod z rozdzia³u 5.10.1 "Warunki koñcowe" ksi¹¿ki
// "Programming -- Principles and Practice Using C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Bad_area { };    // Specjalny typ do raportowania b³êdów w funkcji area().

// Oblicza pole powierzchni prostok¹ta.
// Zg³asza wyj¹tek Bad_area, gdy pojawi siê nieprawid³owy argument.
int area1(int length, int width)
{
    if (length<=0 || width <=0) throw Bad_area();
    return length*width;
}

//------------------------------------------------------------------------------

int area(int length, int width)
// Oblicza pole powierzchni prostok¹ta.
// Warunki wstêpne: length i width maj¹ wartoœci dodatnie.
// Warunek koñcowy: zwraca dodatni¹ wartoœæ wyznaczaj¹c¹ pole powierzchni.
{
    if (length<=0 || width <=0) error("Warunek wstêpny funkcji area().");
    int a =  length*width;
    if (a<=0) error("Warunek koñcowy funkcji area().");
    return a;
}

//------------------------------------------------------------------------------

int main()
try
{
    area(2000000000, 2000000000);
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
