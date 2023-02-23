
//
// Przyk�adowy kod z rozdzia�u 4.3.3 "Konwersje" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double d = 2.5;
    int i = 2;

    double d2 = d/i; // d2 == 1.25
    int i2 = d/i;    // i2 == 1

    d2 = d/i;        // d2 == 1.25
    i2 = d/i;        // i2 == 1

    {
        double dc;
        cin >> dc;
        double df = 9/5*dc+32;    // Uwaga!
    }

    {
        double dc;
        cin >> dc;
        double df = 9.0/5*dc+32;  // lepiej
    }
}

//------------------------------------------------------------------------------
