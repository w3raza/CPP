
//
// To jest przyk�adowy kod z podrozdzia�u 24.2 �Rozmiar, precyzja i przekroczenie zakresu� ksi��ki
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
        int x = 2100000009;    // du�a liczba ca�kowita
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
    char c = i;      // Tak, typ char reprezentuje naprawd� ma�e liczby ca�kowite.
    short s = i;     // Uwaga: liczba ca�kowita mo�e by� za du�a dla typu short.
    i = i+1;         // Co by by�o, gdyby i by�a najwi�ksz� liczb� typu int?
    long lg = i*i;   // Uwaga: liczba typu long nie mo�e by� wi�ksza od typu int.
    float fps = fpd; // Uwaga: du�a liczba typu double mo�e nie zmie�ci� si� w typie float.
    i = fpd;         // Obci�cie: np., 5.7 �> 5.
    fps = i;         // Mo�e zosta� utracona precyzja (w przypadku bardzo du�ych warto�ci typu int).
}

//------------------------------------------------------------------------------

void g()
{
    char ch = 0;
    for (int i = 0; i<500; ++i) 
        cout << int(ch++) << '\t';
}

//------------------------------------------------------------------------------
