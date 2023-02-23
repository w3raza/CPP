
//
// Przyk�adowy kod z rozdzia�u 5.5 "B��dy czasu wykonania" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width)         // Oblicza pole powierzchni prostok�ta.
{
    return length*width;
}

//------------------------------------------------------------------------------

int framed_area(int x, int y)           // Oblicza pole powierzchni w ramce.
{
    return area(x-2,y-2);
}

//------------------------------------------------------------------------------

int main()
{
    int x = -1;
    int y = 2;
    int z = 4;
    // ...
    int area1 = area(x,y);
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3; // Konwersja na typ double, aby wykona� dzielenie
        // zmiennoprzecinkowe.
}

//------------------------------------------------------------------------------
