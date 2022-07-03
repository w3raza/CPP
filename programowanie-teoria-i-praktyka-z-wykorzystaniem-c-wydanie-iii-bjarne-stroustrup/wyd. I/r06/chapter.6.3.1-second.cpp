
//
// Przyk�adowy kod z rozdzia�u 6.3.1 "Pierwsza pr�ba" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Wpisz wyra�enie (obs�ugujemy operatory +, �, * i /):  ";
    int lval = 0;
    int rval;
    char op;
    cin>>lval;               // Wczytywanie pierwszego argumentu wyra�enia z lewej.
    if (!cin) error("Na pocz�tku nie ma argumentu wyra�enia.");
    while (cin>>op) {        // Wczytywanie operatora i prawego argumentu wyra�enia na zmian�.
        cin>>rval;
        if (!cin) error("Nie ma drugiego argumentu wyra�enia.");
        switch(op) {
        case '+':
            lval += rval;    // Dodawanie: lval = lval + rval
            break;
        case '-':
            lval -= rval;    // Odejmowanie: lval = lval � rval
            break;
        case '*':
            lval *= rval;    // Mno�enie: lval = lval * rval
            break;
        case '/':
            lval /= rval;    // Dzielenie: lval = lval / rval
            break;
        default:             // Koniec operator�w � drukowanie wyniku.
            cout << "Wynik: " << lval << '\n';
            keep_window_open();
            return 0;
        }
    }
    error("Nieprawid�owe wyra�enie.");
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
