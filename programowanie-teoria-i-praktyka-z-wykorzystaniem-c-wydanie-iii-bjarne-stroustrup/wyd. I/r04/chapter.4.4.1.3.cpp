
//
// Przyk�adowy kod z rozdzia�u 4.4.1.3 "Instrukcja switch" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()        // Etykiety case musz� by� sta�ymi.
{
    // Definicje alternatywnych przypadk�w:
    int y = 'y';             // Z tym b�d� problemy.
    const char n = 'n';
    const char m = '?'; 
    cout << "Lubisz ryby?\n";
    char a;
    cin >> a;
    switch (a) {
        case n:
            // ...
            //case y:        // B��d: zmienna w etykiecie case.
            // ...
        case m:
            // ...
            //case 'n':      // B��d: duplikat etykiety case (warto�� n to 'n').
            // ...
        default:
            // ...
            ;
    }
}

//------------------------------------------------------------------------------
