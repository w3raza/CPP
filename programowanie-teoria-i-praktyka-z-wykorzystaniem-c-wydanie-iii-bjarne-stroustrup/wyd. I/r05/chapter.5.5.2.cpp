
//
// Przyk�adowy kod z rozdzia�u 5.5.2 "Rozwi�zywanie problemu przez wywo�ywanego" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int area(int length, int width);    // Oblicza pole powierzchni prostok�ta.

//------------------------------------------------------------------------------

int framed_area(int x, int y)        // Oblicza pole w ramce.
{ 
    const int frame_width = 2;
    if (x-frame_width<=0 || y-frame_width<=0)
        error("Argument funkcji area() wywo�anej przez framed_area() nie jest dodatni.");
    return area(x-frame_width,y-frame_width);
}

//------------------------------------------------------------------------------

int area(int length, int width)    // Oblicza pole powierzchni prostok�ta.
{
    if (length<=0 || width <=0)
        error("Argument funkcji area() nie jest dodatni.");
    return length*width;
}

//------------------------------------------------------------------------------

int main()
try
{
    int x = -1;
    int y = 2;
    int z = 4;
    // ...
    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;    // Konwersja na typ double, aby wykona� dzielenie
        // zmiennoprzecinkowe.
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
