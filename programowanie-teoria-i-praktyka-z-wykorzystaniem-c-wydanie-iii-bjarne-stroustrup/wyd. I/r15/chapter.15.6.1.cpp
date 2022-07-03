
//
// To jest przyk�adowy kod z podrozdzia�u 15.6.1 �Odczyt danych z pliku� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Simple_window.h"  // Do��cza bibliotek� graficzn�.
#include "Graph.h"          // Do��cza narz�dzia graficzne.
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

struct Distribution {
    int year, young, middle, old;
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Distribution& d)
// Przyj�ty format: ( rok : m�ody �redni stary )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.year
        >> ch2 >> dd.young >> dd.middle >> dd.old
        >> ch3) {
            if (ch1!= '(' || ch2!=':' || ch3!=')') {
                is.clear(ios_base::failbit);
                return is;
            }
    }
    else
        return is;
    d = dd;
    return is;
}

//------------------------------------------------------------------------------

class Scale {                // warto�� do konwersji wsp�rz�dnych
    int cbase;               // podstawa wsp�rz�dnych
    int vbase;               // baza warto�ci
    double scale;
public:
    Scale(int b, int vb, double s) :cbase(b), vbase(vb), scale(s) { }
    int operator()(int v) const { return cbase + (v-vbase)*scale; }
};

//------------------------------------------------------------------------------

int main()
try
{
    const int xmax = 600;    // Rozmiar okna.
    const int ymax = 400;

    const int xoffset = 100; // Odleg�o�� od lewej kraw�dzi do osi y.
    const int yoffset = 60;  // Odleg�o�� od dolnej kraw�dzi do osi x.

    const int xspace = 40;   // Przestrze� poza osi�.
    const int yspace = 40; 

    const int xlength = xmax-xoffset-xspace;    // D�ugo�� osi.
    const int ylength = ymax-yoffset-yspace;

    const int base_year = 1960;
    const int end_year  = 2040;

    const double xscale
        = double(xlength)/(end_year-base_year); // skalowanie warto�ci x
    const double yscale = double(ylength)/100;  // skalowanie warto�ci y

    Scale xs(xoffset,base_year,xscale);
    Scale ys(ymax-yoffset,0,-yscale);

    string file_name = "japanese-age-data.txt";
    ifstream ifs(file_name.c_str());
    if (!ifs) error("Nie mo�na otworzy� pliku ",file_name);

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;

    Distribution d;
    while (ifs>>d) {
        if (d.year<base_year || end_year<d.year) error("Rok poza zakresem");
        if (d.young+d.middle+d.old != 100) error("Nieprawid�owa suma procent�w.");
        int x = xs(d.year);
        children.add(Point(x,ys(d.young)));
        adults.add(Point(x,ys(d.middle)));
        aged.add(Point(x,ys(d.old)));
    }

    Simple_window win(Point(100,100),xmax,ymax,"Grupy wiekowe w Japonii");

    Axis x(Axis::x, Point(xoffset,ymax-yoffset), xlength,
        (end_year-base_year)/10, 
        "year   1960      1970      1980      1990      "
        "2000      2010      2020      2030      2040");
    x.label.move(-100,0);

    Axis y(Axis::y, Point(xoffset,ymax-yoffset), ylength, 10,"% populacji");

    Line current_year(Point(xs(2008),ys(0)),Point(xs(2008),ys(100)));
    current_year.set_style(Line_style::dash);

    Text children_label(Point(20,children.point(0).y),"wiek 0-14");
    children.set_color(Color::red);
    children_label.set_color(Color::red);

    Text adults_label(Point(20,adults.point(0).y),"wiek 15-64");
    adults.set_color(Color::blue);
    adults_label.set_color(Color::blue);

    Text aged_label(Point(20,aged.point(0).y),"wiek 65+");
    aged.set_color(Color::dark_green);
    aged_label.set_color(Color::dark_green);

    win.attach(children);
    win.attach(adults);
    win.attach(aged);

    win.attach(children_label);
    win.attach(adults_label);
    win.attach(aged_label);

    win.attach(x);
    win.attach(y); 
    win.attach(current_year);

    win.wait_for_button();
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
