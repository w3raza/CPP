
//
// To jest przyk³adowy kod z podrozdzia³u 17.9.2 „WskaŸniki, referencje i dziedziczenie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // Do³¹cza narzêdzia naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

void rotate(Shape* s, int n);  // Obraca *s o n stopni.

//------------------------------------------------------------------------------

int main()
{
    Shape* p = new Circle(Point(100,100),40);
    Circle c(Point(200,200),50);
    rotate(&c,45);
}

//------------------------------------------------------------------------------
