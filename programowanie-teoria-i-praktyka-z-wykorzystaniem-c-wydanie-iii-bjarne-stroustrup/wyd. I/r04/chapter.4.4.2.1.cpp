//
// Przyk³adowy kod z rozdzia³u 4 "Wykonywanie obliczeñ" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int square(int x) // Zwraca kwadrat x.
{
    return x*x;
}

//------------------------------------------------------------------------------

// Oblicza i drukuje tabelê kwadratów z zakresu 0-99.
int main()
{
    int i = 0;    // Zaczyna od 0.
    while (i<100) {
        cout << i << '\t' << square(i) << '\n';
        ++i ;     // Zwiêksza i o jeden (tzn. i staje siê i+1).
    }
}

//------------------------------------------------------------------------------
