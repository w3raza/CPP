
//
// To jest przyk³adowy kod z rozdzia³u 3.3 "Typy danych wejœciowych" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje imiê i wiek (druga wersja programu).
int main()
{
    cout << "Podaj imiê i wiek\n";
    string first_name = "???"; // zmienna ³añcuchowa
                               // ("???" oznacza "imiê nieznane")
    int age = -1;              // zmienna ca³kowitoliczbowa (–1 oznacza "wiek nieznany")
    cin >> first_name >> age;  // wczytuje ³añcuch i liczbê ca³kowit¹
    cout << "Witaj, " << first_name << " (wiek " << age << ")\n";
}

//------------------------------------------------------------------------------
