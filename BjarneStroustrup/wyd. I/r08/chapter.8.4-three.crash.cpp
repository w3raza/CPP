
//
// To jest przyk³adowy kod z podrozdzia³u 8.4 "Zakres" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int g(int x)        // Funkcja g() jest globalna. Zmienna x jest lokalna w tej funkcji.
{
    int f = x+2;    // Zmienna f jest lokalna.
    return 2*f; 
}

//------------------------------------------------------------------------------

int x;    // Zmienna globalna — nale¿y unikaæ ich stosowania, kiedy tylko siê da.
int y;

class C {
public:
    struct M { 
        // ...
    }; 
    // ...
};

//------------------------------------------------------------------------------

void f()
{
    class L {
        // ...
    };
    // ...

    //void g()    // Niedozwolone
    //{
    //    // ...
    //}
    // ...

}

//------------------------------------------------------------------------------

void f1(int x, int y)
{
    if (x>y) {
        // ...
    }
    else {
        // ...
        {
            // ...
        }
        // ...
    }
}

//------------------------------------------------------------------------------

// Niebezpiecznie brzydki kod.
struct X {
void f(int x) {
struct Y {
int f() { return 1; } int m; };
int m;
m=x; Y m2;
return f(m2.f()); }
int m; void g(int m) {
if (m) f(m+2); else {
g(m+2); }}
X() { } void m3() {
}

void main() {
X a; a.f(2);}
};

int main()
{
    g(0);
    f();
    f1(0,1);

    X x;
    x.main();
    x.m3();
}

//------------------------------------------------------------------------------
