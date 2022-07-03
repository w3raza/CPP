
//
// Przyk�adowy kod z rozdzia�u 5.6.1 "Nieprawid�owe argumenty" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Bad_area { };    // Specjalny typ przeznaczony do raportowania b��d�w w funkcji area().

//------------------------------------------------------------------------------

// Oblicza pole powierzchni prostok�ta.
// Zg�asza wyj�tek Bad_area, je�li funkcji zostanie przekazany nieprawid�owy argument.
int area(int length, int width)
{
    if (length<=0 || width <=0) throw Bad_area();
    return length*width;
}

//------------------------------------------------------------------------------

int framed_area(int x, int y)        // Oblicza pole powierzchni w ramce.
{ 
    const int frame_width = 2;
    if (x-frame_width<=0 || y-frame_width<=0)
        error("Argument funkcji area() wywo�anej przez framed_area() nie jest dodatni.");
    return area(x-frame_width,y-frame_width);
}

//------------------------------------------------------------------------------

int main()
try {
    int x = -1;
    int y = 2;
    int z = 4;
    // ...
    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = area1/area3;
}
catch (Bad_area) {
    cout << "Nieprawid�owe argumenty dla funkcji area().\n";
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
