
//
// Przyk³adowy kod z rozdzia³u 4.5.1 "Po co zaprz¹ta sobie g³owê funkcjami" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print_square(int v)
{
    cout << v << '\t' << v*v << '\n';
}

//------------------------------------------------------------------------------

int main()
{
    for (int i = 0; i<100; ++i) print_square(i);
}

//------------------------------------------------------------------------------
