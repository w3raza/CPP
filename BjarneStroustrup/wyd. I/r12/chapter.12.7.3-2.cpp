
//
// To jest przyk�adowy kod z podrozdzia�u 12.7.3 �Klasa Axis� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"    // Dla przycisku �Next�.
#include "Graph.h" 
#include "std_lib_facilities.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main ()
try
{ 
    Point tl(100,100);                   // Lewy g�rny r�g naszego okna.

    Simple_window win(tl,600,400,"Canvas");
    // Wsp�rz�dna ekranu tl okre�laj�ca po�o�enie lewego g�rnego rogu okna.
    // Rozmiar okna 600*400.
    // Tytu�: Kanwa.

    Axis xa(Axis::x, Point(20,300), 280, 10, "x axis"); // Tworzy o�.
    // O� jest rodzajem figury.
    // Axis::x oznacza o� poziom�.
    // Pocz�tek w punkcie (20,300),
    // d�ugo�� 280 pikseli,
    // 10 kresek podzia�ki,
    // etykieta �o� x�.
    win.attach(xa);                      // Wi��e o� xa z oknem win.

    Axis ya(Axis::y, Point(20,300), 280, 10, "y axis");
    ya.set_color(Color::cyan);           // Wyb�r koloru.
    ya.label.set_color(Color::dark_red); // Wyb�r koloru dla tekstu.
    win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();               // Wy�wietl!
} 
catch(exception& e) {
    // Raport o b��dzie.
    return 1;
}
catch(...) {
    // Raport o b��dzie.
    return 2;
}

//------------------------------------------------------------------------------
