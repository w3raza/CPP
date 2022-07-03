
//
// To jest przyk³adowy kod z podrozdzia³u 8.5.6 "Przekazywanie przez wartoœæ a przez referencjê" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(int a, int& r, const int& cr)
{
    ++a;    // Zmienia lokaln¹ wartoœæ a.
    ++r;    // Zmienia obiekt wskazywany przez r
    //++cr; // B³¹d: cr jest sta³¹.
}

//------------------------------------------------------------------------------

void g(int a, int& r, const int& cr)
{
    ++a;        // Zmienia lokaln¹ wartoœæ a.
    ++r;        // Zmienia obiekt wskazywany przez r
    int x = cr; // Odczytuje obiekt wskazywany przez cr.
}

//------------------------------------------------------------------------------

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;

    g(x,y,z);   // x==0; y==1; z==0
    //g(1,2,3); // B³¹d: argument referencyjny r musi odwo³ywaæ siê do zmiennej.
    g(1,y,3);   // Dobrze: poniewa¿ cr jest sta³¹, mo¿na przekazaæ litera³.
    // Oznacza: int __produkcja_kompilatora = 3; g(1,y,__produkcja_kompilatora).
}

//------------------------------------------------------------------------------

int incr1(int a) { return a+1; } // Zwraca jako wynik now¹ wartoœæ.
void incr2(int& a) { ++a; }      // Modyfikuje obiekt przekazany przez referencjê.

void foo()
{
    int x = 7;
    x = incr1(x); // Oczywiste.
    incr2(x);     // Bardzo niejasne.
}

//------------------------------------------------------------------------------

void larger(vector<int>& v1, vector<int>& v2)
// Zamienia ka¿dy element w wektorze v1 na wiêkszy z odpowiadaj¹cych sobie elementów w v1 i v2.
{
    for (int i=0; i<v1.size(); ++i)
        if (v1[i]<v2[i])
            swap(v1[i],v2[i]);
}

//------------------------------------------------------------------------------

void f()
{
    vector<int> vx;
    vector<int> vy;
    // Wczytuje vx i vy z wejœcia.
    larger(vx,vy);
    // ...
}

//------------------------------------------------------------------------------
