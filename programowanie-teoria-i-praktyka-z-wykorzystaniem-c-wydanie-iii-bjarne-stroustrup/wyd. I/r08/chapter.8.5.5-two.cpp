
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.5 �Przekazywanie przez referencj� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int g(int& x);
int f(int& x);

void h(int x, int y)
{
    int i = 7; 
    int& r = i;    // r jest referencj� do i.
    r = 9;         // i otrzymuje warto�� 9.
    i = 10;
    cout << r << ' ' << i << '\n'; // Drukuje: 10 10.

    vector< vector<double> > v;    // Wektor wektor�w liczb typu double.

    double val = v[f(x)][g(y)];    // val jest warto�ci� wyra�enia v[f(x)][g(y)].
    double& var = v[f(x)][g(y)];   // var jest referencj� do v[f(x)][g(y)].

    var = var/2+sqrt(var);
}

//------------------------------------------------------------------------------

// Przekazywanie przez referencj� (funkcja odwo�uje si� do przekazanej jej zmiennej).
int f(int& x)
{
    x = x+1;
    return x;
}

//------------------------------------------------------------------------------

int main()
{
    int xx = 0;
    cout << f(xx) << endl;         // Drukuje: 1.
    cout << xx << endl;            // Drukuje: 1; funkcja f() zmieni�a warto�� xx.

    int yy = 7;
    cout << f(yy) << endl;         // Drukuje: 8.
    cout << yy << endl;            // Drukuje: 8; funkcja f() zmieni�a warto�� yy.
}

//------------------------------------------------------------------------------

int g(int& x)
{
    x = x+1;
    return x;
}

//------------------------------------------------------------------------------
