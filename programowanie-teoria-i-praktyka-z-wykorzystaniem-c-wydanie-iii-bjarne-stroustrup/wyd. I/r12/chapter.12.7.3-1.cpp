
//
// To jest przyk³adowy kod z podrozdzia³u 12.7.3 "Axis" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Dla przycisku „Next”.
#include "Graph.h" 
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{ 
    Point tl(100,100);          // Lewy górny róg naszego okna.

    Simple_window win(tl,600,400,"Kanwa");
    // Wspó³rzêdna ekranu tl okreœlaj¹ca po³o¿enie lewego górnego rogu okna.
    // Rozmiar okna 600*400.
    // Tytu³: Kanwa.

    Axis xa(Axis::x, Point(20,300), 280, 10, "oœ x"); // Tworzy oœ.
    // Oœ jest rodzajem figury.
    // Axis::x oznacza oœ poziom¹.
    // Pocz¹tek w punkcie (20,300),
    // d³ugoœæ 280 pikseli,
    // 10 kresek podzia³ki,
    // etykieta „oœ x”.

    win.attach(xa);             // Wi¹¿e oœ xa z oknem win.
    win.set_label("Canvas #2"); // Zmiana etykiety okna
    win.wait_for_button();      // Wyœwietl!
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
