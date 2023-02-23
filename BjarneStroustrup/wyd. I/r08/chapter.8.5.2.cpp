
//
// To jest przyk³adowy kod z podrozdzia³u 8.5.2 „Zwracanie wartoœci” ksi¹¿ki 
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
    T t(v);             // Inicjuje t wartoœci¹ v.

}

//------------------------------------------------------------------------------

double my_abs(int x)    // Ostrze¿enie: kod z b³êdami.
{
    if (x < 0)
        return -x;
    else if (x> 0)
        return x;
}    // B³¹d: jeœli x ma wartoœæ 0, nie zostanie zwrócona ¿adna wartoœæ.

void print_until_s(const vector<string> v, const string quit)
{
    for(int i=0; i<v.size(); ++i) {
        if (v[i]==quit) return;
        cout << v[i] << '\n';
    }
}

//------------------------------------------------------------------------------
