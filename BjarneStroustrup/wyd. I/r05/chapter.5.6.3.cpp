
//
// Przyk³adowy kod z rozdzia³u 5.6.3 "Nieprawid³owe dane wejœciowe" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double some_function()
{
    double d = 0;
    cin >> d;
    if (!cin) error("Nie mo¿na wczytaæ liczby typu double w funkcji 'some_function()'.");
    // Jakieœ przydatne instrukcje.
}

//------------------------------------------------------------------------------

int main()
try {
    // Nasz program.
    some_function();
    return 0;    // 0 oznacza powodzenie.
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n';
    keep_window_open();
    return 1;    // 1 oznacza niepowodzenie.
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n";
    keep_window_open();
    return 2;    // 2 oznacza niepowodzenie.
}

//------------------------------------------------------------------------------
