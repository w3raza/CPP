
//
// To jest przyk³adowy kod z rozdzia³u 3.3 "Typy danych wejœciowych" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje imiê i wiek.
int main()
{
    cout << "Podaj imiê i wiek\n";
    string first_name;  // zmienna ³añcuchowa
    int age;            // zmienna ca³kowitoliczbowa
    cin >> first_name;  // odczyt ³añcucha
    cin >> age;         // odczyt liczby ca³kowitej
    cout << "Witaj, " << first_name << " (wiek " << age << ")\n";
}

//------------------------------------------------------------------------------
