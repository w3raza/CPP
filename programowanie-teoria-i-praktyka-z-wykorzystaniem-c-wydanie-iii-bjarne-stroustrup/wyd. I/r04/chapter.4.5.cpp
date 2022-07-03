
//
// Przyk³adowy kod z rozdzia³u 4.5 "Funkcje" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int square(int x)    // Zwraca kwadrat x.
{
    return x*x;
}

//------------------------------------------------------------------------------

void write_sorry()    // Nie pobiera ¿adnych argumentów i nic nie zwraca.
{
    cout << "Przykro mi.\n";
}

//------------------------------------------------------------------------------

int main()
{
    cout << square(2) << '\n';  // drukuje 4
    cout << square(10) << '\n'; // drukuje 100

    square(2);                  // Prawdopodobnie to jest b³¹d: wartoœæ zwrotna nie jest u¿ywana.
    //int v1 = square();        // B³¹d: brak argumentu.
    //int v2 = square;          // B³¹d: brak nawiasów.
    //int v3 = square(1,2);     // B³¹d: za du¿o argumentów.
    //int v4 = square("two");   // B³¹d: z³y typ argumentu - powinien byæ int.

    write_sorry();
}

//------------------------------------------------------------------------------
