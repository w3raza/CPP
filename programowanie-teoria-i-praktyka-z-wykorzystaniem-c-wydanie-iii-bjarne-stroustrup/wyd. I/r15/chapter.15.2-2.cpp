
//
// To jest przyk³adowy kod z podrozdzia³u 15.2 "Rysowanie wykresów prostych funkcji" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza bibliotekê graficzn¹.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

double one(double) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;    // Rozmiar okna.
    const int ymax = 400;

    const int x_orig = xmax/2;    // Punkt (0,0) jest œrodkiem okna.
    const int y_orig = ymax/2; 
    const Point orig(x_orig,y_orig);

    const int r_min = -10;    // zakres <–10,11) 
    const int r_max = 11;

    const int n_points = 400;    // liczba punktów w zakresie

    const int x_scale = 30;    // wspó³czynniki skalowania
    const int y_scale = 30;

    Simple_window win0(Point(100,100),xmax,ymax,"Wykresy funkcji");

    Function s1(one,   r_min,r_max,orig,n_points,x_scale,y_scale);
    Function s2(slope, r_min,r_max,orig,n_points,x_scale,y_scale);
    Function s3(square,r_min,r_max,orig,n_points,x_scale,y_scale);

    win0.attach(s1);
    win0.attach(s2);
    win0.attach(s3);

    Text ts(Point(100,y_orig-40),"one");
    Text ts2(Point(100,y_orig+y_orig/2-20),"x/2");
    Text ts3(Point(x_orig-100,20),"x*x");
    win0.attach(ts);
    win0.attach(ts2);
    win0.attach(ts3);
    win0.set_label("Wykresy funkcji: etykiety");
    win0.wait_for_button();
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
