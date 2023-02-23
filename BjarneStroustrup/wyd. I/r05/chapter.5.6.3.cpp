
//
// Przyk�adowy kod z rozdzia�u 5.6.3 "Nieprawid�owe dane wej�ciowe" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double some_function()
{
    double d = 0;
    cin >> d;
    if (!cin) error("Nie mo�na wczyta� liczby typu double w funkcji 'some_function()'.");
    // Jakie� przydatne instrukcje.
}

//------------------------------------------------------------------------------

int main()
try {
    // Nasz program.
    some_function();
    return 0;    // 0 oznacza powodzenie.
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n';
    keep_window_open();
    return 1;    // 1 oznacza niepowodzenie.
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n";
    keep_window_open();
    return 2;    // 2 oznacza niepowodzenie.
}

//------------------------------------------------------------------------------
