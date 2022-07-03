
//
// Przyk³adowy kod z rozdzia³u 5.6.1 "Nieprawid³owe argumenty" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Bad_area { };    // Specjalny typ przeznaczony do raportowania b³êdów w funkcji area().

//------------------------------------------------------------------------------

// Oblicza pole powierzchni prostok¹ta.
// Zg³asza wyj¹tek Bad_area, jeœli funkcji zostanie przekazany nieprawid³owy argument.
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
        error("Argument funkcji area() wywo³anej przez framed_area() nie jest dodatni.");
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
    cout << "Nieprawid³owe argumenty dla funkcji area().\n";
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
