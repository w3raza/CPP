
//
// To jest przyk�adowy kod z podrozdzia�u 12.7.6 "Prostok�ty" ksi��ki
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
    Point tl(100,100);    // Lewy g�rny r�g naszego okna.

    Simple_window win(tl,600,400,"Kanwa");
    // Wsp�rz�dna ekranu tl okre�laj�ca po�o�enie lewego g�rnego rogu okna.
    // Rozmiar okna 600*400.
    // Tytu�: Kanwa.

    Axis xa(Axis::x, Point(20,300), 280, 10, "o� x"); // Tworzy o�.
    // O� jest rodzajem figury.
    // Axis::x oznacza o� poziom�.
    // Pocz�tek w punkcie (20,300),
    // d�ugo�� 280 pikseli,
    // 10 kresek podzia�ki,
    // etykieta �o� x�.
    win.attach(xa);                      // Wi��e o� xa z oknem win.

    Axis ya(Axis::y, Point(20,300), 280, 10, "o� y");
    ya.set_color(Color::cyan);           // Wyb�r koloru.
    ya.label.set_color(Color::dark_red); // Wyb�r koloru dla tekstu.
    win.attach(ya);

    Function sine(sin,0,100,Point(20,150),1000,50,50);    // sinusoida
    // Rysuje funkcj� sin() w przedziale <0,100) z punktem (0,0) w punkcie (20,150),
    win.attach(sine);
    sine.set_color(Color::blue);         // Zmienili�my zdanie na temat koloru funkcji sinus.

    Polygon poly;                        // Wielok�t � jest rodzajem figury (Shape).
    poly.add(Point(300,200));            // Trzy punkty tworz� tr�jk�t.
    poly.add(Point(350,100));
    poly.add(Point(400,200));

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    Rectangle r(Point(200,200), 100, 50);// Lewy g�rny r�g, szeroko��, wysoko��.
    win.attach(r); 

    Closed_polyline poly_rect;
    poly_rect.add(Point(100,50)); 
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(100,100));
    win.attach(poly_rect);

    win.set_label("Kanwa nr 6.1");
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
