
//
// Przyk�adowy kod z rozdzia�u 4.5.1 "Po co zaprz�ta sobie g�ow� funkcjami" ksi��ki
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
