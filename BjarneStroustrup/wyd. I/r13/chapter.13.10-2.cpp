
//
// To jest przyk�adowy kod z podrozdzia�u 13.10 �Wykorzystywanie obiekt�w bez nazw� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza nasz� bibliotek� okien.
#include "Graph.h"          // Do��cza narz�dzia graficzne.

//------------------------------------------------------------------------------

int main()
try
{
    using namespace Graph_lib;   // Nasze narz�dzia graficzne znajduj� si� w bibliotece Graph_lib

    Simple_window win(Point(100,100),600,400,"Kolorowa matryca o wymiarach 16*16.");
    Vector_ref<Rectangle> vr;

    for (int i = 0; i<16; ++i)
        for (int j = 0; j<16; ++j) {
            vr.push_back(new Rectangle(Point(i*20,j*20),20,20));
            vr[vr.size()-1].set_fill_color(Color(i*16+j));
            win.attach(vr[vr.size()-1]);
        }

    win.wait_for_button();       // Wy�wietl!
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
