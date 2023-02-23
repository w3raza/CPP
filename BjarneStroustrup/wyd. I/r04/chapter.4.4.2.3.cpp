
//
// Przyk�adowy kod z rozdzia�u 4.4.2.3 "Instrukcje for" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int square(int x)    // Zwraca kwadrat x.
{
    return x*x;
}

//------------------------------------------------------------------------------

// Oblicza i drukuje tabel� kwadrat�w z zakresu 0-99.
int main()
{
    for (int i = 0; i<100; ++i) {    // Dla i z zakresu [0:100).
        cout << i << '\t' << square(i) << '\n';
        //++i; // Co tu si� dzieje? Pachnie b��dem!
    }
}

//------------------------------------------------------------------------------
