
//
// To jest przyk�adowy kod z rozdzia�u 3.3 "Typy danych wej�ciowych" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje imi� i wiek.
int main()
{
    cout << "Podaj imi� i wiek\n";
    string first_name;  // zmienna �a�cuchowa
    int age;            // zmienna ca�kowitoliczbowa
    cin >> first_name;  // odczyt �a�cucha
    cin >> age;         // odczyt liczby ca�kowitej
    cout << "Witaj, " << first_name << " (wiek " << age << ")\n";
}

//------------------------------------------------------------------------------
