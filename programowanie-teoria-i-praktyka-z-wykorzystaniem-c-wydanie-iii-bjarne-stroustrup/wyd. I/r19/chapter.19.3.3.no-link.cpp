
//
// To jest przyk�adowy kod z podrozdzia�u 19.3.3 �Kontenery a dziedziczenie� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // Do��cza narz�dzia z naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main()
{
    vector<Shape> vs;
    vector<Circle> vc;
    //vs = vc;       // B��d: wymagany vector<Shape>.
    void f(vector<Shape>&);
    //f(vc);         // B��d: wymagany vector<Shape>.

    vector<Shape*> vps;
    vector<Circle*> vpc;
    //vps = vpc;     // B��d: wymagany vector<Shape*>.
    void f(vector<Shape*>&);
    //f(vpc);        // B��d: wymagany vector<Shape*>.
}

//------------------------------------------------------------------------------

void f(vector<Shape*>& v)
{
    v.push_back(new Rectangle(Point(0,0),Point(100,100)));
}

//------------------------------------------------------------------------------
