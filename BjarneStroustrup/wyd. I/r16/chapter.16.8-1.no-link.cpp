
//
// To jest przyk³adowy kod z podrozdzia³u 16.8 „Debugowanie kodu GUI" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do³¹cza nasz¹ bibliotekê okien.
#include "GUI.h"
#include "Point.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

void cb_flood(Address, Address);
void cb_fire(Address, Address);

//------------------------------------------------------------------------------

// Funkcja pomocnicza do ³adowania przycisków do menu.
void load_disaster_menu(Menu& m)
{
    Point orig(0,0);
    Button b1(orig,0,0,"flood",cb_flood); 
    Button b2(orig,0,0,"fire",cb_fire);
    // ...
    m.attach(b1);
    m.attach(b2);
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    Simple_window win(Point(100,100),600,400,"Katastrofy");
    // ...
    Menu disasters(Point(0,0),70,20,Menu::vertical,"Kolor");
    load_disaster_menu(disasters);
    win.attach(disasters);
    // ...
}
catch(exception& e) {
    // Raport o b³êdzie
    return 1;
}
catch(...) {
    // Raport o b³êdzie
    return 2;
}

//------------------------------------------------------------------------------
