
//
// Przyk�adowy kod z rozdzia�u 5.5.1 "Rozwi�zywanie problemu przez wywo�uj�cego" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int area(int length, int width)    // Oblicza pole powierzchni prostok�ta.
{
    return length*width;
}

//------------------------------------------------------------------------------

const int frame_width = 2;
int framed_area(int x, int y)        // Oblicza pole w ramce.
{
    return area(x-frame_width,y-frame_width);
}

//------------------------------------------------------------------------------

int main()
try
{
    int x = -1;
    int y = 2;
    int z = 4;
    // ...

    {
        if (x<=0) error("Warto�� x nie jest dodatnia.");
        if (y<=0) error("Warto�� y nie jest dodatnia.");
        int area1 = area(x,y);
    }

    {
        // Gdyby�my nie potrzebowali osobnych komunikat�w dla na temat ka�dego argumentu, mogliby�my upro�ci� kod:
        if (x<=0 || y<=0) error("Argument funkcji area() nie jest dodatni.");   // ||  oznacza "lub"
        int area1 = area(x,y); 

        if (z<=2) 
            error("Drugi argument funkcji area() wywo�anej przez framed_area() nie jest dodatni.");

        int area2 = framed_area(1,z); 
        if (y<=2 || z<=2)
            error("Argument funkcji area() wywo�anej przez framed_area() nie jest dodatni.");
        int area3 = framed_area(y,z);
        double ratio = double(area1)/area3;    // Konwersja na typ double, aby wykona� dzielenie
        // zmiennoprzecinkowe.
    }

    {
        if (1-frame_width<=0 || z-frame_width<=0)
            error("Drugi argument funkcji area() wywo�anej przez framed_area() nie jest dodatni.");
        int area2 = framed_area(1,z); 
        if (y-frame_width<=0 || z-frame_width<=0)
            error("Argument funkcji area() wywo�anej przez framed_area() nie jest dodatni.");
        int area3 = framed_area(y,z);
    }
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
