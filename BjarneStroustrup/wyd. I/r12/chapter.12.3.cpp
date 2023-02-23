
//
// To jest przyk�adowy kod z podrozdzia�u 12.3 �Pierwszy przyk�ad� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Do��cza nasz� bibliotek� okien.
#include "Graph.h"            // Do��cza nasz� bibliotek� narz�dzi graficznych.

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // Nasze narz�dzia graficzne znajduj� si� w przestrzeni nazw Graph_lib.

    Point tl(100,100);           // Lewy g�rny r�g okna.

    Simple_window win(tl,600,400,"Canvas");    // Tworzy proste okno.

    Polygon poly;                // Tworzy figur� (wielok�t).

    poly.add(Point(300,200));    // Dodaje punkt.
    poly.add(Point(350,100));    // Dodaje drugi punkt.
    poly.add(Point(400,200));    // Dodaje trzeci punkt. 

    poly.set_color(Color::red);  // Ustawia w�a�ciwo�ci wielok�ta.

    win.attach (poly);           // Wi��e wielok�t z oknem.

    win.wait_for_button();       // Przekazuje kontrol� mechanizmowi wy�wietlaj�cemu.
}

//------------------------------------------------------------------------------
