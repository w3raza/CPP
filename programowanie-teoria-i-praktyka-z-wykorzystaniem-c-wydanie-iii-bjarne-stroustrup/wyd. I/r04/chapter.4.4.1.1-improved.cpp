
//
// Przyk�adowy kod z rozdzia�u 4.4.1.1 ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Konwertuje cale na centymetry i centymetry na cale.
// Przyrostek 'i' lub 'c' oznacza jednostk� na wej�ciu.
// Ka�dy inny przyrostek oznacza b��d.

int main()
{
    const double cm_per_inch = 2.54;  // Liczba centymetr�w w calu.
    int length = 1;                   // D�ugo�� w calach lub centymetrach.
    char unit = ' ';                  // Spacja nie jest jednostk�.
    cout<< "Podaj liczb� i jednostk� (c lub i):\n";
    cin >> length >> unit;

    if (unit == 'i')
        cout << length << "in == " << cm_per_inch*length << "cm\n";
    else if (unit == 'c')
        cout << length << "cm == " << length/cm_per_inch << "in\n";
    else
        cout << "Przykro mi, nie znam jednostki o nazwie '" << unit << "'\n";
}

//------------------------------------------------------------------------------
