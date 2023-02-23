
//
// To jest przyk³adowy kod z rozdzia³u 3.1 "Dane wejœciowe" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje i drukuje imiê.
int main()
{
    cout << "Podaj imiê (i naciœnij klawisz Enter):\n";
    string first_name;    // first_name to zmienna typu string.
    cin >> first_name;    // Wczytuje znaki do zmiennej first_name.
    cout << "Witaj, " << first_name << "!\n";
    cout << "first_name" << " ma wartoœæ " << first_name;
}

//------------------------------------------------------------------------------
