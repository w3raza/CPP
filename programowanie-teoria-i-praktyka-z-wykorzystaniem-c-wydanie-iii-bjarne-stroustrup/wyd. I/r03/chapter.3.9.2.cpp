
//
// To jest przyk�adowy kod z rozdzia�u 3.9.2 "Konwersje niebezpieczne dla typ�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int a = 20000;
    char c = a; // Pr�ba wci�ni�cia du�ej liczby typu int w ma�y typ char.
    int b = c;
    if (a != b) // != oznacza "jest r�ny od"
        cout << "Ups!: " << a << "!=" << b << '\n';
    else
        cout << "Wow! Mamy du�e znaki.\n";
}

//------------------------------------------------------------------------------
