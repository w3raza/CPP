
//
// Przyk³adowy kod z rozdzia³u 5.5 "B³êdy czasu wykonania" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width)         // Oblicza pole powierzchni prostok¹ta.
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
    double ratio = double(area1)/area3; // Konwersja na typ double, aby wykonaæ dzielenie
        // zmiennoprzecinkowe.
}

//------------------------------------------------------------------------------
