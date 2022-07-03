
//
// To jest przyk³adowy kod z podrozdzia³u 12.7.2 "Prawie puste okno" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Dla przycisku „Next”
#include "Graph.h" 
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{ 
    Point tl(100,100);     // Lewy górny róg naszego okna.

    Simple_window win(tl,600,400,"Canvas");
    // Wspó³rzêdna ekranu tl okreœlaj¹ca po³o¿enie lewego górnego rogu okna.
    // Rozmiar okna 600*400.
    // Tytu³: Kanwa.
    win.wait_for_button(); // Wyœwietl!
} 
catch(exception& e) {
    // Raport o b³êdzie.
    return 1;
}
catch(...) {
    // Raport o b³êdzie.
    return 2;
}

//------------------------------------------------------------------------------
