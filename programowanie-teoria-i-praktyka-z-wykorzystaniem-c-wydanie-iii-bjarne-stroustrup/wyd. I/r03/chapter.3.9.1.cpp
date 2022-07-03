
//
// To jest przyk�adowy kod z rozdzia�u 3.9.1 "Konwersje bezpieczne dla typ�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    char c = 'x';
    int i1 = c;
    int i2 = 'x';
    char c2 = i1;

    cout << c << ' ' << i1 << ' ' << c2 << '\n'; // Zostanie wydrukowane: x 120 x.

    double d1 = 2.3;
    double d2 = d1+2; // 2 zostanie przed dodaniem przekonwertowana na 2.0.

    if (d1 < 0)       // 0 zostanie przed por�wnaniem przekonwertowane na 0.0.
        cout << "d1 ma ujemn� warto��";
}

//------------------------------------------------------------------------------
