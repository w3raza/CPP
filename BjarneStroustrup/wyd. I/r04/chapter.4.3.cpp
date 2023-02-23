
//
// Przyk³adowy kod z rozdzia³u 4.3 "Wyra¿enia" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    // Oblicza pole powierzchni: 
    int length = 20;         // Litera³ ca³kowitoliczbowy (do inicjacji zmiennej)
    int width = 40;
    int area = length*width; // mno¿enie

    length = 99;             // Przypisanie zmiennej length wartoœci 99.

    {
        int perimeter = (length+width)*2; // Dodawanie i mno¿enie.
    }

    {
        int perimeter = length*2+width*2;
    }

    {
        int perimeter = length+width/2;    // Dodanie wartoœci width*2 do zmiennej length.
    }
}

//------------------------------------------------------------------------------
