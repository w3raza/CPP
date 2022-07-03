
//
// To jest przyk³adowy kod z podrozdzia³u 25.4.4 „Dziedziczenie a kontenery” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class T>
class Array_ref {
public:
    Array_ref(T* pp, int s) : p(pp), sz(s) { }

    template<class Q> 
    operator const Array_ref<const Q>()
    {
        // Sprawdza niejawne konwersje elementów:
        sizeof(static_cast<Q>(*static_cast<T*>(0)));
        // Rzutuje Array_ref:
        return Array_ref<const Q>(reinterpret_cast<Q*>(p),sz);
    }

    T& operator[ ](int n) { return p[n]; }
    const T& operator[ ](int n) const { return p[n]; }

    bool assign(Array_ref a)
    {
        if (a.sz!=a) return false;
        for (int i=0; i<sz; ++i) { p[i]=a.p[i]; }
    }

    void reset(Array_ref a) { reset(a.p,a.sz); }
    void reset(T* pp, int s) { p=pp; sz=s; }

    int size() const { return sz; }

    // Domyœlne operacje kopiowania:
    // Array_ref nie ma ¿adnych zasobów.
    // Array_ref ma semantykê referencyjn¹.
private:
    T* p;
    int sz;
};

//------------------------------------------------------------------------------

template <class T> Array_ref<T> make_ref(T* pp, int s)
{
    return (pp) ? Array_ref<T>(pp,s) : Array_ref<T>(0,0);
}

//------------------------------------------------------------------------------

template <class T> Array_ref<T> make_ref(vector<T>& v)
{
    return (v.size()) ? Array_ref<T>(&v[0],v.size()) : Array_ref<T>(0,0);
}

//------------------------------------------------------------------------------

template <class T, int s> Array_ref<T> make_ref(T (&pp)[s])
{
    return Array_ref<T>(pp,s);
}

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

void better2(const Array_ref<Shape*const> a)
{
    for (int  i = 0; i<a.size(); ++i) 
        if (a[i])
            a[i]->draw();
}

//------------------------------------------------------------------------------

void f(Shape* q, vector<Circle*>& s0)
{
    const int max = 25;
    Polygon* s1[10]; 
    Shape* s2[20];
    // initialize
    Shape* p1 = new Rectangle(Point(0,0),Point(10,20));
    better2(make_ref(s0));       // B³¹d: wymagany Array_ref<Shape>.
    better2(make_ref(s1));       // B³¹d: wymagany Array_ref<Shape>.
    better2(make_ref(s2));       // Dobrze (nie potrzeba konwersji).
    //better2(make_ref(p1,1));   // b³¹d
    //better2(make_ref(q,max));  // b³¹d
}

//------------------------------------------------------------------------------
