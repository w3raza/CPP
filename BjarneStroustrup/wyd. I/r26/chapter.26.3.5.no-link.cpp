
//
// To jest przyk³adowy kod z podrozdzia³u 26.3.5 „Testowanie klas” ksi¹¿ki
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

class Shape  {        // Obs³uguje kolory i style oraz przechowuje sekwencjê linii.
public:
    void draw() const;            // Obs³uguje kolory i rysuje linie.
    virtual void move(int dx, int dy);    // Przesuwa figurê +=dx i +=dy.

    void set_color(Color col);
    int color() const;

    void set_style(Line_style sty);
    Line_style style() const;

    void set_fill_color(Color col);
    Color fill_color() const;

    Point point(int i) const;        // Dostêp tylko do odczytu do punktów.
    int number_of_points() const;

    virtual ~Shape() { }
protected:
    Shape();    
    virtual void draw_lines() const;    // Rysuje odpowiednie linie.
    void add(Point p);            // Dodaje p do punktów.
    void set_point(int i,Point p);        // points[i]=p;
private:
    vector<Point> points;        // Nie u¿ywane przez wszystkie figury.
    Color lcolor;        // Kolor linii i znaków.
        Line_style ls; 
    Color fcolor;        // Kolor wype³nienia.

    Shape(const Shape*);        // Uniemo¿liwia kopiowanie.
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
    ln.draw();             // Sprawdzanie czy siê pojawi.
    
    // Sprawdzanie punktów:
    if (ln.number_of_points() != 2) cerr << "Nieprawid³owa liczba punktów.";
    if (ln.point(0)!=Point(10,10)) cerr<< "Nieprawid³owy pierwszy punkt.";
    if (ln.point(1)!=Point(100,100)) cerr<< "Nieprawid³owy drugi punkt.";
    
    for (int i=0; i<10; ++i) {    // Sprawdzanie czy siê przesuwa:
          ln.move(i+5,i+5);
          ln.draw();
        }
    for (int i=0; i<10; ++i) {    // Sprawdzanie czy wraca do pocz¹tku:
          ln.move(i-5,i-5); 
          ln.draw();
        }
    if (ln.point(0)!=Point(10,10)) cerr<< "Nieprawid³owy pierwszy punkt po przesuniêciu.";
    if (ln.point(1)!=Point(100,100)) cerr<< "Nieprawid³owy drugi punkt po przesuniêciu.";

    for (int i = 0; i<100; ++i) {    // Sprawdzanie czy kolor zmienia siê prawid³owo:
          ln.set_color(Color(i*100));
        if (ln.color() != i*100) cerr << "Nieprawid³owe dzia³anie set_color.";
        ln.draw();
    }
    
    for (int i = 0; i<100; ++i) {    // Sprawdzanie czy styl zmienia siê prawid³owo.
          ln.set_style(Line_style(i*5));
        if (ln.style() != i*5) cerr << "Nieprawid³owe dzia³anie set_style.";
        ln.draw();
    }
}

//------------------------------------------------------------------------------
