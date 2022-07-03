
//
// To jest przyk³adowy kod z podrozdzia³u 16.7 „Dodawanie menu” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <sstream>
#include "Graph.h"         // Do³¹cza narzêdzia graficzne.
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title );
private:
    // Dane:
    Open_polyline lines;

    // Widgety:
    Button next_button;    // Dodaje (next_x,next_y) do linii.
    Button quit_button;    // Zamyka program
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button menu_button;

    void change(Color c) { lines.set_color(c); } 

    void hide_menu() { color_menu.hide(); menu_button.show(); } 

    // Operacje wywo³ywane przez funkcje zwrotne:
    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); } 
    void black_pressed() { change(Color::black); hide_menu(); } 
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void next(); 
    void quit(); 

    // Funkcje zwrotne:
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address); 
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    color_menu(Point(x_max()-70,30),70,20,Menu::vertical,"Kolor"),
    menu_button(Point(x_max()-80,30), 80, 20, "Menu kolorów", cb_menu),
    next_button(Point(x_max()-150,0), 70, 20, "Nastêpny punkt", cb_next),
    quit_button(Point(x_max()-70,0), 70, 20, "Koniec", cb_quit),
    next_x(Point(x_max()-310,0), 50, 20, "x:"),
    next_y(Point(x_max()-210,0), 50, 20, "y:"),
    xy_out(Point(100,0), 100, 20, "Bie¿¹cy punkt (x,y):")
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("Brak punktów");
    color_menu.attach(new Button(Point(0,0),0,0,"czerwony",cb_red));
    color_menu.attach(new Button(Point(0,0),0,0,"niebieski",cb_blue));
    color_menu.attach(new Button(Point(0,0),0,0,"czarny",cb_black));
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    attach(lines);
}

//------------------------------------------------------------------------------

void Lines_window::cb_quit(Address, Address pw)    // typowa
{  
       reference_to<Lines_window>(pw).quit();
} 

//------------------------------------------------------------------------------

void Lines_window::quit()
{
    hide();        // Ciekawy sposób zastosowany w FLTK do usuwania okna.
}

//------------------------------------------------------------------------------

void Lines_window::cb_next(Address, Address pw)     // typowa
{  
       reference_to<Lines_window>(pw).next();
} 

//------------------------------------------------------------------------------

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x,y));

    // Aktualizuje pole z bie¿¹cym punktem:
    stringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

      redraw();
}

//------------------------------------------------------------------------------

void Lines_window::cb_red(Address, Address pw)      // typowa
{  
    reference_to<Lines_window>(pw).red_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_blue(Address, Address pw)     // typowa
{  
    reference_to<Lines_window>(pw).blue_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_black(Address, Address pw)    // typowa
{  
    reference_to<Lines_window>(pw).black_pressed();
} 

//------------------------------------------------------------------------------

void Lines_window::cb_menu(Address, Address pw)     // typowa
{  
    reference_to<Lines_window>(pw).menu_pressed();
} 

//------------------------------------------------------------------------------

int main()
try {
    Lines_window win(Point(100,100),600,400,"Linie");
    return gui_main();
}
catch(exception& e) {
    cerr << "Wyj¹tek: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Jakiœ wyj¹tek\n";
    return 2;
}

//------------------------------------------------------------------------------
