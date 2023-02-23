
//
// To jest przyk�adowy kod z podrozdzia�u 17.9.2 �Wska�niki, referencje i dziedziczenie� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // Do��cza narz�dzia naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

void rotate(Shape& s, int n);  // Obraca *s o n stopni.

//------------------------------------------------------------------------------

int main()
{
    Circle c(Point(200,200),50);
    Shape& r = c;
    rotate(c,75);
}

//------------------------------------------------------------------------------
