
//
// To jest przyk�adowy kod z podrozdzia�u 19.3.2 �Programowanie og�lne� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "../GUI/Graph.h" // Do��cza narz�dzia z naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

void shape_test(vector<Shape*>& v, Shape* x, Shape& s)
{
    v.push_back(x);  // Wstawia x do wektora v.
    s.draw();        // Rysuje figur� s.
}

//------------------------------------------------------------------------------

void draw_all(vector<Shape*>& v)
{
    for (int i=0; i<v.size(); ++i) v[i]->draw();
}

//------------------------------------------------------------------------------
