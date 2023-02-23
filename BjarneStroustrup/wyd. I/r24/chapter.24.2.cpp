
//
// To jest przyk³adowy kod z podrozdzia³u 24.2 „Rozmiar, precyzja i przekroczenie zakresu” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <iomanip>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    {
        float x = 1.0/333;
        float sum = 0;
        for (int i=0; i<333; ++i) sum+=x;
        cout << setprecision(15) << sum << "\n";
    }

    {
        short y = 40000;
        int i = 1000000;
        cout << y << "   " << i*i << "\n";
    }

    {
        cout << "sizes: " << sizeof(int) << ' ' << sizeof(float) << '\n';
        int x = 2100000009;    // du¿a liczba ca³kowita
        float f = x;
        cout << x << ' ' << f << endl;
        cout << setprecision(15) << x << ' ' << f << '\n';
    }
    {
        float f = 2.8;
        int x = f;
        cout << x << ' ' << f << endl;
    }
}

//------------------------------------------------------------------------------

void f(int i, double fpd)
{
    char c = i;      // Tak, typ char reprezentuje naprawdê ma³e liczby ca³kowite.
    short s = i;     // Uwaga: liczba ca³kowita mo¿e byæ za du¿a dla typu short.
    i = i+1;         // Co by by³o, gdyby i by³a najwiêksz¹ liczb¹ typu int?
    long lg = i*i;   // Uwaga: liczba typu long nie mo¿e byæ wiêksza od typu int.
    float fps = fpd; // Uwaga: du¿a liczba typu double mo¿e nie zmieœciæ siê w typie float.
    i = fpd;         // Obciêcie: np., 5.7 –> 5.
    fps = i;         // Mo¿e zostaæ utracona precyzja (w przypadku bardzo du¿ych wartoœci typu int).
}

//------------------------------------------------------------------------------

void g()
{
    char ch = 0;
    for (int i = 0; i<500; ++i) 
        cout << int(ch++) << '\t';
}

//------------------------------------------------------------------------------
