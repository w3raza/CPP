
//
// To jest przyk�adowy kod z podrozdzia�u 8.4 "Zakres" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(int x)       // Funkcja f() jest globalna. Zmienna x jest lokalna w tej funkcji.
{
    int z = x+7;    // Zmienna z jest lokalna.
}

//------------------------------------------------------------------------------

int g(int x)        // Funkcja g() jest globalna. Zmienna x jest lokalna w tej funkcji.
{
    int f = x+2;    // Zmienna f jest lokalna.
    return 2*f; 
}

//------------------------------------------------------------------------------

int max(int a, int b) // Funkcja max() jest globalna. Zmienne a i b s� lokalne.
{
    return (a>=b) ? a : b;
}

//------------------------------------------------------------------------------

int my_abs(int a)     // To nie jest a funkcji max().
{
    return (a<0) ? -a : a;
}

//------------------------------------------------------------------------------

int max2(int a, int b) // Funkcja max2() jest globalna. a i b s� lokalne.
{
    int m;            // Zmienna m jest lokalna.
    if (a>=b) 
        m = a;
    else
        m = b;
    return m;
}

//------------------------------------------------------------------------------

// Nie ma tu r, i ani v.
class My_vector {
    vector<int> v;    // v nale�y do zakresu klasy.
public:
    int largest()
    {
        int r = 0;    // Zmienna r jest lokalna (najmniejsza nieujemna liczba typu int).
        for (int i = 0; i<v.size(); ++i)
            r = max(r,my_abs(v[i]));    // i nale�y do zakresu instrukcji for.
        // Tutaj nie ma i.
        return r;
    }
    // Tutaj nie ma r.
};

//------------------------------------------------------------------------------
// Tutaj nie ma v.

int x;                // Zmienna globalna � nale�y unika� ich stosowania, kiedy tylko si� da.
int y;

int f()
{
    int x;            // Zmienna lokalna
    x = 7;            // Lokalna zmienna x.
    {
        int x = y;    // Lokalna zmienna x zainicjowana globaln� zmienn� y.
        ++x;          // x z poprzedniego wiersza.
    }
    ++x;              // x z pierwszego wiersza funkcji f().
    return x;
}

//------------------------------------------------------------------------------

class C {
public:
    void f();
    void g()          // Funkcj� sk�adow� mo�na zdefiniowa� w klasie.
    { 
        // ...
    } 
    // ...
};

//------------------------------------------------------------------------------

void C::f()           // Definicja sk�adowej mo�e znajdowa� si� poza klas�.
{
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    f();
    return my_abs(max(f(),g(0)) - max2(f(),g(1)));
}

//------------------------------------------------------------------------------
