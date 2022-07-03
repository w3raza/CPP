
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.2 �Zwracanie warto�ci� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef int T;
typedef double V;

T f()                  // Funkcja f() zwraca T.
{
    V v;
    // ...
    return v;
}

//------------------------------------------------------------------------------

int main()
{
    T x = f();
    V v;
    // ...
    T t(v);             // Inicjuje t warto�ci� v.

}

//------------------------------------------------------------------------------

double my_abs(int x)    // Ostrze�enie: kod z b��dami.
{
    if (x < 0)
        return -x;
    else if (x> 0)
        return x;
}    // B��d: je�li x ma warto�� 0, nie zostanie zwr�cona �adna warto��.

void print_until_s(const vector<string> v, const string quit)
{
    for(int i=0; i<v.size(); ++i) {
        if (v[i]==quit) return;
        cout << v[i] << '\n';
    }
}

//------------------------------------------------------------------------------
