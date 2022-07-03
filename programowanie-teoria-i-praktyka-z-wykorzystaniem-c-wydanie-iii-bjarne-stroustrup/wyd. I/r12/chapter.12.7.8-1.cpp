
//
// To jest przyk³adowy kod z podrozdzia³u 12.7.8 "Tekst" ksi¹¿ki
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
    win.attach(xa);                      // Wi¹¿e oœ xa z oknem win.

    Axis ya(Axis::y, Point(20,300), 280, 10, "oœ y");
    ya.set_color(Color::cyan);           // Wybór koloru.
    ya.label.set_color(Color::dark_red); // Wybór koloru dla tekstu.
    win.attach(ya);

    Function sine(sin,0,100,Point(20,150),1000,50,50);    // sinusoida
    // Rysuje funkcjê sin() w przedziale <0,100) z punktem (0,0) w punkcie (20,150),
    win.attach(sine);
    sine.set_color(Color::blue);         // Zmieniliœmy zdanie na temat koloru funkcji sinus.

    Polygon poly;                        // Wielok¹t — jest rodzajem figury (Shape).
    poly.add(Point(300,200));            // Trzy punkty tworz¹ trójk¹t.
    poly.add(Point(350,100));
    poly.add(Point(400,200));

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);

    Rectangle r(Point(200,200), 100, 50);// Lewy górny róg, szerokoœæ, wysokoœæ.
    win.attach(r); 

    Closed_polyline poly_rect;
    poly_rect.add(Point(100,50)); 
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(100,100));
    poly_rect.add(Point(50,75));
    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);    // Koloruje wnêtrze prostok¹ta.
    poly.set_style(Line_style(Line_style::dash,4)); 
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);

    Text t(Point(150,150), "Witaj, graficzny œwiecie! ");
    win.attach(t);

    win.set_label("Kanwa nr 8");
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
