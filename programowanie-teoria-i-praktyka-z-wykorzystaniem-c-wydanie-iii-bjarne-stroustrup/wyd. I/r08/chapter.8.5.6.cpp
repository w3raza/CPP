
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.6 "Przekazywanie przez warto�� a przez referencj�" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(int a, int& r, const int& cr)
{
    ++a;    // Zmienia lokaln� warto�� a.
    ++r;    // Zmienia obiekt wskazywany przez r
    //++cr; // B��d: cr jest sta��.
}

//------------------------------------------------------------------------------

void g(int a, int& r, const int& cr)
{
    ++a;        // Zmienia lokaln� warto�� a.
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
    //g(1,2,3); // B��d: argument referencyjny r musi odwo�ywa� si� do zmiennej.
    g(1,y,3);   // Dobrze: poniewa� cr jest sta��, mo�na przekaza� litera�.
    // Oznacza: int __produkcja_kompilatora = 3; g(1,y,__produkcja_kompilatora).
}

//------------------------------------------------------------------------------

int incr1(int a) { return a+1; } // Zwraca jako wynik now� warto��.
void incr2(int& a) { ++a; }      // Modyfikuje obiekt przekazany przez referencj�.

void foo()
{
    int x = 7;
    x = incr1(x); // Oczywiste.
    incr2(x);     // Bardzo niejasne.
}

//------------------------------------------------------------------------------

void larger(vector<int>& v1, vector<int>& v2)
// Zamienia ka�dy element w wektorze v1 na wi�kszy z odpowiadaj�cych sobie element�w w v1 i v2.
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
    // Wczytuje vx i vy z wej�cia.
    larger(vx,vy);
    // ...
}

//------------------------------------------------------------------------------
