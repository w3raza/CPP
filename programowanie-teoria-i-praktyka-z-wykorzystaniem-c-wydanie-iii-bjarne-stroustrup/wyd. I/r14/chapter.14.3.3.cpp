
//
// To jest przyk³adowy kod z podrozdzia³u 14.3.3 „Przes³anianie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

struct B {
    virtual void f() const { cout << "B::f  "; }
    void g() const { cout << "B::g  "; }  // niewirtualna
};

//------------------------------------------------------------------------------

struct D : B {
    void f() const { cout << "D::f  "; }  // Przes³ania B::f.
    void g() { cout << "D::g  "; }
};

//------------------------------------------------------------------------------

struct DD : D {
    void f() { cout << "DD::f  "; }       // Nie przes³ania D::f (nie const).
    void g() const { cout << "DD::g  "; }
};

//------------------------------------------------------------------------------

void call(const B& b)
    // D jest rodzajem B, a wiêc funkcja call() mo¿e przyjmowaæ argumenty typu D.
    // DD jest rodzajem D, zaœ D jest rodzajem B, a wiêc funkcja call() mo¿e przyjmowaæ argumenty typu DD.
{
    b.f();
    b.g();
}

//------------------------------------------------------------------------------

int main()
try
{
    B b;
    D d;
    DD dd;

    call(b);
    call(d);
    call(dd);

    b.f();
    b.g();

    d.f();
    d.g();

    dd.f();
    dd.g();
}
catch(exception& e) {
    // Raport o b³êdzie.
    return 1;
}
catch(...) {
    // Raport o b³êdzie.
    return 2;
}

//------------------------------------------------------------------------------
