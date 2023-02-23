
//
// Przyk³adowy kod z rozdzia³u 4.4.1.2 "Instrukcje switch" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    const double cm_per_inch = 2.54; // Liczba centymetrów w calu.
    int length = 1;                  // D³ugoœæ length w calach lub centymetrach.
    char unit = 'a';
    cout<< "Podaj liczbê i jednostkê (c lub i):\n";
    cin >> length >> unit;
    switch (unit) {
    case 'i':
        cout << length << "in == " << cm_per_inch*length << "cm\n";
        break;
    case 'c':
        cout << length << "cm == " << length/cm_per_inch << "in\n";
        break;
    default:
        cout << "Przykto mi, ale nie znam jednostki o nazwie '" << unit << "'\n";
        break;
    }
}

//------------------------------------------------------------------------------
