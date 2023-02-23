
//
// To jest przyk³adowy kod z podrozdzia³u 13.10 „Wykorzystywanie obiektów bez nazw" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "Graph.h"          // Do³¹cza narzêdzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    Vector_ref<Rectangle> rect;

    Rectangle x(Point(100,200),Point(200,300));
    rect.push_back(x);    // dodaje nazwany obiekt

    rect.push_back(new Rectangle(Point(50,60),Point(80,90))); // dodaje nienazwany obiekt

    for (int i=0; i<rect.size(); ++i) rect[i].move(10,10);    // u¿ycie prostok¹ta
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
