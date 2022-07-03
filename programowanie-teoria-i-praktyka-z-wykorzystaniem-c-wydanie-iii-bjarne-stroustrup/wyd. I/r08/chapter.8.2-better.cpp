
//
// To jest przyk�adowy kod z podrozdzia�u 8.2 "Deklaracje i definicje" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"     // W tym pliku znajduje si� deklaracja strumienia cout.

//------------------------------------------------------------------------------

int f(int);              // Deklaracja f.

int main()
{
    int i = 7;           // Deklaracja i.
    cout << f(i) << '\n';
}

//------------------------------------------------------------------------------

double my_sqrt(double);  // Brak tre�ci funkcji.
extern int a;            // Brak warto�ci inicjuj�cej oznacza brak definicji.

int a;                   // Definicja
//int a;                 // B��d: podw�jna definicja.

int x = 7;               // Definicja
extern int x;            // Deklaracja
extern int x;            // Inna deklaracja

double my_sqrt(double);  // Deklaracja
double my_sqrt(double d) { return 0.0; }    // Definicja
//double my_sqrt(double d) { return 1.0; }    // B��d: podw�jna definicja.
double my_sqrt(double);  // Inna deklaracja my_sqrt
double my_sqrt(double);  // Kolejna deklaracja my_sqrt.

//int my_sqrt(double);   // B��d: niesp�jne deklaracje funkcji sqrt.

double expression();     // Tylko deklaracja, nie definicja.

double primary()
{
    // ...
    return expression();
    // ...
}

//------------------------------------------------------------------------------

double term()
{
    // ...
    return primary();
    // ...
}

//------------------------------------------------------------------------------

double expression()
{
    // ...
    return term();
    // ...
}

//------------------------------------------------------------------------------

int f(int n) { return n; }
