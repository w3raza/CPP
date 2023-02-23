
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.1 �Deklarowanie argument�w i typu zwrotnego� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double fct(int a, double d);            // Deklaracja funkcji fct() (bez tre�ci).
double fct(int a, double d) { return a*d; }    // Definicja funkcji fct().

int current_power();        // Funkcja current_power() nie pobiera argument�w.

void increase_power(int level);    // Funkcja increase_power() nie zwraca warto�ci.

// Szuka s w vs.
// vs[hint] mo�e by� dobrym miejscem do rozpocz�cia szukania.
// Zwraca indeks znalezionego elementu. Warto�� -1 oznacza, �e nic nie znaleziono.
int my_find(vector<string> vs, string s, int hint); // Argumenty z nazwami.

int my_find(vector<string>, string, int);           // Argumenty bez nazw.

int my_find(vector<string> vs, string s, int hint)
// Szuka s w vs zaczynaj�c od hint.
{
    if (hint<0 || vs.size()<=hint) hint = 0;
    for (int i = hint; i<vs.size(); ++i)            // Szuka zaczynaj�c od hint.
        if (vs[i]==s) return i;
    if (0<hint) {    // Je�li nie znajdzie s, szuka przed hint.
        for (int i = 0; i<hint; ++i)
            if (vs[i]==s) return i;
    }
    return -1;    
}

//------------------------------------------------------------------------------

namespace different
{

    int my_find(vector<string> vs, string s, int)   // Trzeci argument pozostaje nieu�yty.
    {
        for (int i = 0; i<vs.size(); ++i)
            if (vs[i]==s) return i;
        return -1;    
    }    

}

//------------------------------------------------------------------------------

int main()
{
    const int   N = 4;
    const char* cities[N] = {"Aarhus", "Brussels", "Cincinnati", "Dublin"};
    vector<string> v(cities, cities+N);
    return my_find(v, "Dublin", 2) == different::my_find(v, "Dublin", 2);
}

//------------------------------------------------------------------------------
