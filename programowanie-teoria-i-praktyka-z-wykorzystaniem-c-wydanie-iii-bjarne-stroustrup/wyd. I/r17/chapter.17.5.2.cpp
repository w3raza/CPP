
//
// To jest przyk³adowy kod z podrozdzia³u 17.5.2 „Destruktory a pamiêæ wolna” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // Do³¹cza narzêdzia naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

Shape* fct()
{
    Text tt(Point(200,200),"Anna");
    // ...
    Shape* p = new Text(Point(100,100),"Miko³aj");
    return p;
}

//------------------------------------------------------------------------------

void f()
{
    Shape* q = fct();
    // ...
    delete q;
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
