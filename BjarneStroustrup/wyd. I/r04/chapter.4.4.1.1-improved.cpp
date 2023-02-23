
//
// Przyk³adowy kod z rozdzia³u 4.4.1.1 ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Konwertuje cale na centymetry i centymetry na cale.
// Przyrostek 'i' lub 'c' oznacza jednostkê na wejœciu.
// Ka¿dy inny przyrostek oznacza b³¹d.

int main()
{
    const double cm_per_inch = 2.54;  // Liczba centymetrów w calu.
    int length = 1;                   // D³ugoœæ w calach lub centymetrach.
    char unit = ' ';                  // Spacja nie jest jednostk¹.
    cout<< "Podaj liczbê i jednostkê (c lub i):\n";
    cin >> length >> unit;

    if (unit == 'i')
        cout << length << "in == " << cm_per_inch*length << "cm\n";
    else if (unit == 'c')
        cout << length << "cm == " << length/cm_per_inch << "in\n";
    else
        cout << "Przykro mi, nie znam jednostki o nazwie '" << unit << "'\n";
}

//------------------------------------------------------------------------------
