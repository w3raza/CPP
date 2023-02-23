
//
// To jest przyk³adowy kod z podrozdzia³u 8.2 "Deklaracje i definicje" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"     // W tym pliku znajduje siê deklaracja strumienia cout.

//------------------------------------------------------------------------------

int f(int);              // Deklaracja f.

int main()
{
    int i = 7;           // Deklaracja i.
    cout << f(i) << '\n';
}

//------------------------------------------------------------------------------

double my_sqrt(double);  // Brak treœci funkcji.
extern int a;            // Brak wartoœci inicjuj¹cej oznacza brak definicji.

int a;                   // Definicja
//int a;                 // B³¹d: podwójna definicja.

int x = 7;               // Definicja
extern int x;            // Deklaracja
extern int x;            // Inna deklaracja

double my_sqrt(double);  // Deklaracja
double my_sqrt(double d) { return 0.0; }    // Definicja
//double my_sqrt(double d) { return 1.0; }    // B³¹d: podwójna definicja.
double my_sqrt(double);  // Inna deklaracja my_sqrt
double my_sqrt(double);  // Kolejna deklaracja my_sqrt.

//int my_sqrt(double);   // B³¹d: niespójne deklaracje funkcji sqrt.

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
