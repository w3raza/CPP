
//
// Przyk�adowy kod z rozdzia�u 4.3 "Wyra�enia" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    // Oblicza pole powierzchni: 
    int length = 20;         // Litera� ca�kowitoliczbowy (do inicjacji zmiennej)
    int width = 40;
    int area = length*width; // mno�enie

    length = 99;             // Przypisanie zmiennej length warto�ci 99.

    {
        int perimeter = (length+width)*2; // Dodawanie i mno�enie.
    }

    {
        int perimeter = length*2+width*2;
    }

    {
        int perimeter = length+width/2;    // Dodanie warto�ci width*2 do zmiennej length.
    }
}

//------------------------------------------------------------------------------
