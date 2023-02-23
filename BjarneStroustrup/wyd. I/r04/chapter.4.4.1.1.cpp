
//
// Przyk�adowy kod z rozdzia�u 4.4.1.1 "Instrukcje if" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int a = 0;
    int b = 0;
	cout << "Podaj dwie liczby ca�kowite:\n";
    cin >> a >> b;

    if (a<b)    // warunek
        // Pierwsza opcja (wykonywana, gdy warunek zostanie spe�niony):
        cout << "max(" << a << "," << b <<") to " << b <<"\n";
    else
        // Druga opcja (wykonywana, gdy warunek nie zostanie spe�niony):
        cout << "max(" << a << "," << b <<") to " << a << "\n";
}

//------------------------------------------------------------------------------

