
//
// To jest przyk�adowy kod z podrozdzia�u 13.10 �Wykorzystywanie obiekt�w bez nazw" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    Vector_ref<Rectangle> rect;

    Rectangle x(Point(100,200),Point(200,300));
    rect.push_back(x);    // dodaje nazwany obiekt

    rect.push_back(new Rectangle(Point(50,60),Point(80,90))); // dodaje nienazwany obiekt

    for (int i=0; i<rect.size(); ++i) rect[i].move(10,10);    // u�ycie prostok�ta
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
