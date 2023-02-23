
//
// Przyk�adowy kod z rozdzia�u 4.5 "Funkcje" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int square(int x)    // Zwraca kwadrat x.
{
    return x*x;
}

//------------------------------------------------------------------------------

void write_sorry()    // Nie pobiera �adnych argument�w i nic nie zwraca.
{
    cout << "Przykro mi.\n";
}

//------------------------------------------------------------------------------

int main()
{
    cout << square(2) << '\n';  // drukuje 4
    cout << square(10) << '\n'; // drukuje 100

    square(2);                  // Prawdopodobnie to jest b��d: warto�� zwrotna nie jest u�ywana.
    //int v1 = square();        // B��d: brak argumentu.
    //int v2 = square;          // B��d: brak nawias�w.
    //int v3 = square(1,2);     // B��d: za du�o argument�w.
    //int v4 = square("two");   // B��d: z�y typ argumentu - powinien by� int.

    write_sorry();
}

//------------------------------------------------------------------------------
