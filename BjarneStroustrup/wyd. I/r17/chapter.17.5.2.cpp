
//
// To jest przyk�adowy kod z podrozdzia�u 17.5.2 �Destruktory a pami�� wolna� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // Do��cza narz�dzia naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

Shape* fct()
{
    Text tt(Point(200,200),"Anna");
    // ...
    Shape* p = new Text(Point(100,100),"Miko�aj");
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
