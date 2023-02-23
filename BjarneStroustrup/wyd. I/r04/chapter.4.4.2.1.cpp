//
// Przyk�adowy kod z rozdzia�u 4 "Wykonywanie oblicze�" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int square(int x) // Zwraca kwadrat x.
{
    return x*x;
}

//------------------------------------------------------------------------------

// Oblicza i drukuje tabel� kwadrat�w z zakresu 0-99.
int main()
{
    int i = 0;    // Zaczyna od 0.
    while (i<100) {
        cout << i << '\t' << square(i) << '\n';
        ++i ;     // Zwi�ksza i o jeden (tzn. i staje si� i+1).
    }
}

//------------------------------------------------------------------------------
