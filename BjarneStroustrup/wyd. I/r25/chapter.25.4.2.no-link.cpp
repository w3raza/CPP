
//
// To jest przyk�adowy kod z podrozdzia�u 25.4.2 �Problem � �le dzia�aj�ce interfejsy� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Point
{
public:
    Point(int x, int y);
};

//------------------------------------------------------------------------------

class Shape 
{
public:
    virtual void draw();
};

//------------------------------------------------------------------------------

class Circle : public Shape { /* ... */ };

//------------------------------------------------------------------------------

class Rectangle : public Shape 
{
public:
    Rectangle(const Point& p1, const Point& p2);
};

//------------------------------------------------------------------------------

class Polygon : public Shape {};

//------------------------------------------------------------------------------

void poor(Shape* p, int sz)    // S�aby projekt interfejsu.
{
    for (int  i = 0; i<sz; ++i) p[i].draw();
}

//------------------------------------------------------------------------------

void f(Shape* q, vector<Circle>& s0)    // very bad code
{
    const int max = 25;
    Polygon s1[10];
    Shape s2[10];
    // initialize
    Shape* p1 = new Rectangle(Point(0,0),Point(10,20)); 
    poor(&s0[0],s0.size());    // #1 (przekazanie tablicy z wektora)
    poor(s1,10);               // #2
    poor(s2,20);               // #3
    poor(p1,1);                // #4
    delete p1;
    p1 = 0;
    poor(p1,1);                // #5
    poor(q,max);               // #6
}

//------------------------------------------------------------------------------

void fv(vector<Shape>&);

//------------------------------------------------------------------------------

void f(Shape &);

//------------------------------------------------------------------------------

void g(vector<Circle>& v, Circle & d)
{
    f(d);       // Dobrze: niejawna konwersja typu Circle na Shape.
    //fv(v);    // B��d: nie da si� konwertowa� typu vector<Circle> na vector<Shape>.
}

//------------------------------------------------------------------------------

void poor(Shape* p, int sz);

//------------------------------------------------------------------------------

void general(vector<Shape>&);

//------------------------------------------------------------------------------
