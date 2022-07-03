
//
// Przyk³adowy kod z rozdzia³u 4.4.1.3 "Instrukcja switch" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()        // Etykiety case musz¹ byæ sta³ymi.
{
    // Definicje alternatywnych przypadków:
    int y = 'y';             // Z tym bêd¹ problemy.
    const char n = 'n';
    const char m = '?'; 
    cout << "Lubisz ryby?\n";
    char a;
    cin >> a;
    switch (a) {
        case n:
            // ...
            //case y:        // B³¹d: zmienna w etykiecie case.
            // ...
        case m:
            // ...
            //case 'n':      // B³¹d: duplikat etykiety case (wartoœæ n to 'n').
            // ...
        default:
            // ...
            ;
    }
}

//------------------------------------------------------------------------------
