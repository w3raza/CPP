
//
// To jest przyk�adowy kod z rozdzia�u 3.1 "Dane wej�ciowe" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje i drukuje imi�.
int main()
{
    cout << "Podaj imi� (i naci�nij klawisz Enter):\n";
    string first_name;    // first_name to zmienna typu string.
    cin >> first_name;    // Wczytuje znaki do zmiennej first_name.
    cout << "Witaj, " << first_name << "!\n";
    cout << "first_name" << " ma warto�� " << first_name;
}

//------------------------------------------------------------------------------
