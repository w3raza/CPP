
//
// To jest przyk³adowy kod z podrozdzia³u 19.3.3 „Kontenery a dziedziczenie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"
#include "../GUI/Graph.h" // Do³¹cza narzêdzia z naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main()
{
    vector<Shape> vs;
    vector<Circle> vc;
    //vs = vc;       // B³¹d: wymagany vector<Shape>.
    void f(vector<Shape>&);
    //f(vc);         // B³¹d: wymagany vector<Shape>.

    vector<Shape*> vps;
    vector<Circle*> vpc;
    //vps = vpc;     // B³¹d: wymagany vector<Shape*>.
    void f(vector<Shape*>&);
    //f(vpc);        // B³¹d: wymagany vector<Shape*>.
}

//------------------------------------------------------------------------------

void f(vector<Shape*>& v)
{
    v.push_back(new Rectangle(Point(0,0),Point(100,100)));
}

//------------------------------------------------------------------------------
