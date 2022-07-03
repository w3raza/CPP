//
// To jest przyk³adowy kod z podrozdzia³u 12.7.4 "Rysowanie wykresu funkcji" ksi¹¿ki
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
    Point tl(100,100);    // Lewy górny róg naszego okna.

    Simple_window win(tl,600,400,"Canvas");
    // Wspó³rzêdna ekranu tl okreœlaj¹ca po³o¿enie lewego górnego rogu okna.
    // Rozmiar okna 600*400.
    // Tytu³: Kanwa.

    Axis xa(Axis::x, Point(20,300), 280, 10, "x axis"); // Tworzy oœ.
    // Oœ jest rodzajem figury.
    // Axis::x oznacza oœ poziom¹.
    // Pocz¹tek w punkcie (20,300),
    // d³ugoœæ 280 pikseli,
    // 10 kresek podzia³ki,
    // etykieta „oœ x”.
    win.attach(xa);                      // Wi¹¿e oœ xa z oknem win.

    Axis ya(Axis::y, Point(20,300), 280, 10, "y axis");
    ya.set_color(Color::cyan);           // Wybór koloru.
    ya.label.set_color(Color::dark_red); // Wybór koloru dla tekstu.
    win.attach(ya);

    Function sine(sin,0,100,Point(20,150),1000,50,50);    // Krzywa obrazuj¹ca sinusoidê.
    // Rysuje funkcjê sin() w przedziale <0,100) z punktem (0,0) w punkcie (20,150),
    // przy u¿yciu 1000 punktów. Skaluje wartoœci x i y *50.
    win.attach(sine);

    win.set_label("Canvas #4");
    win.wait_for_button();               // Wyœwietl!
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
