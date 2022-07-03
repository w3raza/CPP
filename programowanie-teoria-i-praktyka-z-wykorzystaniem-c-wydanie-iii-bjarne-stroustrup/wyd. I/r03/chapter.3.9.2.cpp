
//
// To jest przyk³adowy kod z rozdzia³u 3.9.2 "Konwersje niebezpieczne dla typów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int a = 20000;
    char c = a; // Próba wciœniêcia du¿ej liczby typu int w ma³y typ char.
    int b = c;
    if (a != b) // != oznacza "jest ró¿ny od"
        cout << "Ups!: " << a << "!=" << b << '\n';
    else
        cout << "Wow! Mamy du¿e znaki.\n";
}

//------------------------------------------------------------------------------
