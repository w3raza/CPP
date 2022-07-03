
//
// Przyk�adowy kod z rozdzia�u 4.4.1.2 "Instrukcje switch" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    const double cm_per_inch = 2.54; // Liczba centymetr�w w calu.
    int length = 1;                  // D�ugo�� length w calach lub centymetrach.
    char unit = 'a';
    cout<< "Podaj liczb� i jednostk� (c lub i):\n";
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
