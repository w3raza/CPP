
//
// To jest przyk³adowy kod z podrozdzia³u 15.5 „Wartoœæ przybli¿ona funkcji wyk³adniczej” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <cmath>
#include <sstream>
#include "Simple_window.h"  // Do³¹cza bibliotekê graficzn¹.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

using namespace std;

//------------------------------------------------------------------------------

int fac(int n)    // factorial(n); n!
{
    int r = 1;
    while (n>1) {
        r*=n;
        --n;
    }
    return r;
}

//------------------------------------------------------------------------------

double term(double x, int n) { return pow(x,n)/fac(n); }    // n-ty sk³adnik szeregu

//------------------------------------------------------------------------------

double expe(double x, int n)        // suma n sk³adników dla x
{
    double sum = 0;
    for (int i=0; i<n; ++i) sum+=term(x,i);
    return sum;
}

//------------------------------------------------------------------------------

int expN_number_of_terms = 10;

double expN(double x)
{
    return expe(x,expN_number_of_terms);
}

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;      // Rozmiar okna.
    const int ymax = 400;

    const int x_orig = xmax/2; // Punkt (0,0) jest œrodkiem okna.
    const int y_orig = ymax/2; 
    const Point orig(x_orig,y_orig);

    const int r_min = -10;     // zakres <–10,11) 
    const int r_max = 11;

    const int n_points = 400;  // liczba punktów w zakresie

    const int x_scale = 30;    // wspó³czynniki skalowania
    const int y_scale = 30;

    Simple_window win(Point(100,100),xmax,ymax,"Przybli¿enie wartoœci funkcji wyk³adniczej");

    const int xlength = xmax-40;   // Tworzy nieco krótsz¹ oœ od okna.
    const int ylength = ymax-40;

    Axis x(Axis::x,Point(20,y_orig), xlength, xlength/x_scale, "jedna kreska == 1");
    Axis y(Axis::y,Point(x_orig, ylength+20), ylength, ylength/y_scale, "jedna kreska == 1");
    win.attach(x);
    win.attach(y);
    x.set_color(Color::red);
    y.set_color(Color::red);

    Function real_exp(exp,r_min,r_max,orig,200,x_scale,y_scale);
    real_exp.set_color(Color::blue);
    win.attach(real_exp);

    for (int n = 0; n<50; ++n) {
        ostringstream ss;
        ss << "Przybli¿enie wartoœci funkcji wyk³adniczej; n==" << n ;
        win.set_label(ss.str());
        expN_number_of_terms = n;
        // Nastêpne przybli¿enie:
        Function e(expN,r_min,r_max,orig,200,x_scale,y_scale);
        win.attach(e);
        if (!win.wait_for_button())
            break; // U¿ytkownik zakoñczy³ pracê.
        win.detach(e);
    }

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
