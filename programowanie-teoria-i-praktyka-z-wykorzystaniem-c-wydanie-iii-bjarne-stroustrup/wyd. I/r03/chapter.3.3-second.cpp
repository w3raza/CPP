
//
// To jest przyk�adowy kod z rozdzia�u 3.3 "Typy danych wej�ciowych" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje imi� i wiek (druga wersja programu).
int main()
{
    cout << "Podaj imi� i wiek\n";
    string first_name = "???"; // zmienna �a�cuchowa
                               // ("???" oznacza "imi� nieznane")
    int age = -1;              // zmienna ca�kowitoliczbowa (�1 oznacza "wiek nieznany")
    cin >> first_name >> age;  // wczytuje �a�cuch i liczb� ca�kowit�
    cout << "Witaj, " << first_name << " (wiek " << age << ")\n";
}

//------------------------------------------------------------------------------
