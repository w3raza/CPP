
//
// To jest przyk³adowy kod z podrozdzia³u 14.1.2 "Operacje" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza do narzêdzi graficznych.

//------------------------------------------------------------------------------

void draw_line(Point p1, Point p2);              // od p1 do p2 (nasz styl)
void draw_line(int x1, int y1, int x2, int y2);  // od (x1,y1) do (x2,y2)
void draw_rectangle(Point p, int w, int h);
void draw_rectangle(int x, int y, int w, int h);

//------------------------------------------------------------------------------

int main()
try
{
    Line ln(Point(100,200),Point(300,400));
    Mark m(Point(100,200),'x');                  // Wyœwietla punkt w postaci znaku x.
    Circle c(Point(200,200),250);

    draw_rectangle(Point(100,200), 300, 400);    // Nasz styl
    draw_rectangle (100,200,300,400);            // Alternatywny styl
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
