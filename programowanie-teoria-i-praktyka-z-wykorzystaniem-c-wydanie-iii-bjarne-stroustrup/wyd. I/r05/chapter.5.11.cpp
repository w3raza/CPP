
//
// Przyk�adowy kod z rozdzia�u 5.11 "�wiczenia" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try {
    // <<Tw�j kod>>
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------
