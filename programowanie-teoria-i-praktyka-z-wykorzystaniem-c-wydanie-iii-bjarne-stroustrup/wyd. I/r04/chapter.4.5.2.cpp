
//
// Przyk�adowy kod z rozdzia�u 4.5.2 "Deklarowanie funkcji" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int    square(int);    // Deklaracja funkcji square.
double sqrt(double);   // Deklaracja funkcji sqrt.

int main()
{
    int x = square(44);
}

//------------------------------------------------------------------------------

int square(int x)      // Definicja funkcji square.
{
    return x*x;
}

//------------------------------------------------------------------------------
