
//
// To jest przyk³adowy kod z podrozdzia³u 19.3.2 „Programowanie ogólne” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "../GUI/Graph.h" // Do³¹cza narzêdzia z naszej biblioteki graficznej.

using namespace Graph_lib;

//------------------------------------------------------------------------------

void shape_test(vector<Shape*>& v, Shape* x, Shape& s)
{
    v.push_back(x);  // Wstawia x do wektora v.
    s.draw();        // Rysuje figurê s.
}

//------------------------------------------------------------------------------

void draw_all(vector<Shape*>& v)
{
    for (int i=0; i<v.size(); ++i) v[i]->draw();
}

//------------------------------------------------------------------------------
