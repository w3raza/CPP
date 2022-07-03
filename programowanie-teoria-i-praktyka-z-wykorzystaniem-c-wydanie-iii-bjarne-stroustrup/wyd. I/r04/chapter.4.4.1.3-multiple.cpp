
//
// Przyk�adowy kod z rozdzia�u 4.4.1.3 "Instrukcja switch" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()    // Instrukcja mo�e mie� kilka etykiet.
{ 
	cout << "Podaj cyfr�:\n";
    char a;
    cin >> a;

    switch (a) {
    case '0': case '2': case '4': case '6': case '8':
        cout << "Parzysta\n";
        break;
    case '1': case '3': case '5': case '7': case '9':
        cout << "Nieparzysta\n";
        break;
    default:
        cout << "To nie jest cyfra.\n";
        break;
    }
}

//------------------------------------------------------------------------------
