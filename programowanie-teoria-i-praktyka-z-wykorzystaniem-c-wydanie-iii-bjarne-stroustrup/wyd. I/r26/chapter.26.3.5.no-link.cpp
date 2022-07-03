
//
// To jest przyk�adowy kod z podrozdzia�u 26.3.5 �Testowanie klas� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Color 
{
public:
    Color(int =0);
};

//------------------------------------------------------------------------------

class Line_style 
{
public:
    Line_style(int =0);
    bool operator!=(const Line_style&) const;
};

//------------------------------------------------------------------------------

class Point 
{
public:
    Point(int, int);
    bool operator!=(const Point&) const;
};

//------------------------------------------------------------------------------

class Shape  {        // Obs�uguje kolory i style oraz przechowuje sekwencj� linii.
public:
    void draw() const;            // Obs�uguje kolory i rysuje linie.
    virtual void move(int dx, int dy);    // Przesuwa figur� +=dx i +=dy.

    void set_color(Color col);
    int color() const;

    void set_style(Line_style sty);
    Line_style style() const;

    void set_fill_color(Color col);
    Color fill_color() const;

    Point point(int i) const;        // Dost�p tylko do odczytu do punkt�w.
    int number_of_points() const;

    virtual ~Shape() { }
protected:
    Shape();    
    virtual void draw_lines() const;    // Rysuje odpowiednie linie.
    void add(Point p);            // Dodaje p do punkt�w.
    void set_point(int i,Point p);        // points[i]=p;
private:
    vector<Point> points;        // Nie u�ywane przez wszystkie figury.
    Color lcolor;        // Kolor linii i znak�w.
        Line_style ls; 
    Color fcolor;        // Kolor wype�nienia.

    Shape(const Shape*);        // Uniemo�liwia kopiowanie.
    Shape& operator=(const Shape*);
};

//------------------------------------------------------------------------------

class Line : public Shape 
{
public:
    Line(const Point&, const Point&);
};

//------------------------------------------------------------------------------

int main()
{
    Line ln(Point(10,10), Point(100, 100));
    ln.draw();             // Sprawdzanie czy si� pojawi.
    
    // Sprawdzanie punkt�w:
    if (ln.number_of_points() != 2) cerr << "Nieprawid�owa liczba punkt�w.";
    if (ln.point(0)!=Point(10,10)) cerr<< "Nieprawid�owy pierwszy punkt.";
    if (ln.point(1)!=Point(100,100)) cerr<< "Nieprawid�owy drugi punkt.";
    
    for (int i=0; i<10; ++i) {    // Sprawdzanie czy si� przesuwa:
          ln.move(i+5,i+5);
          ln.draw();
        }
    for (int i=0; i<10; ++i) {    // Sprawdzanie czy wraca do pocz�tku:
          ln.move(i-5,i-5); 
          ln.draw();
        }
    if (ln.point(0)!=Point(10,10)) cerr<< "Nieprawid�owy pierwszy punkt po przesuni�ciu.";
    if (ln.point(1)!=Point(100,100)) cerr<< "Nieprawid�owy drugi punkt po przesuni�ciu.";

    for (int i = 0; i<100; ++i) {    // Sprawdzanie czy kolor zmienia si� prawid�owo:
          ln.set_color(Color(i*100));
        if (ln.color() != i*100) cerr << "Nieprawid�owe dzia�anie set_color.";
        ln.draw();
    }
    
    for (int i = 0; i<100; ++i) {    // Sprawdzanie czy styl zmienia si� prawid�owo.
          ln.set_style(Line_style(i*5));
        if (ln.style() != i*5) cerr << "Nieprawid�owe dzia�anie set_style.";
        ln.draw();
    }
}

//------------------------------------------------------------------------------
