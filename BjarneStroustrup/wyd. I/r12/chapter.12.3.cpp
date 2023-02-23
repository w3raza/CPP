
//
// To jest przyk³adowy kod z podrozdzia³u 12.3 „Pierwszy przyk³ad” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"            // Do³¹cza nasz¹ bibliotekê narzêdzi graficznych.

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // Nasze narzêdzia graficzne znajduj¹ siê w przestrzeni nazw Graph_lib.

    Point tl(100,100);           // Lewy górny róg okna.

    Simple_window win(tl,600,400,"Canvas");    // Tworzy proste okno.

    Polygon poly;                // Tworzy figurê (wielok¹t).

    poly.add(Point(300,200));    // Dodaje punkt.
    poly.add(Point(350,100));    // Dodaje drugi punkt.
    poly.add(Point(400,200));    // Dodaje trzeci punkt. 

    poly.set_color(Color::red);  // Ustawia w³aœciwoœci wielok¹ta.

    win.attach (poly);           // Wi¹¿e wielok¹t z oknem.

    win.wait_for_button();       // Przekazuje kontrolê mechanizmowi wyœwietlaj¹cemu.
}

//------------------------------------------------------------------------------
