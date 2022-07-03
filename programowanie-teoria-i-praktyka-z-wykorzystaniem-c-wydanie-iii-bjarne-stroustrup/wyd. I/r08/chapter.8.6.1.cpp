
//
// To jest przyk³adowy kod z podrozdzia³u 8.6.1 „Wartoœciowanie wyra¿eñ” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<int> v(10);                   // v jest zmienn¹ globaln¹.

void f(int i, int j)
{
    cout << i << ' ' << j << '\n';
}

//------------------------------------------------------------------------------

int main()
{
    int i = 4;
    v[i] = ++i;                      // Nie rób tego: nieokreœlony porz¹dek wartoœciowania.
    v[++i] = i;                      // Nie rób tego: nieokreœlony porz¹dek wartoœciowania.
    int x = ++i + ++i;               // Nie rób tego: nieokreœlony porz¹dek wartoœciowania.
    cout << ++i << ' ' << i << '\n'; // Nie rób tego: nieokreœlony porz¹dek wartoœciowania.
    f(++i,++i);                      // Nie rób tego: nieokreœlony porz¹dek wartoœciowania.
}

//------------------------------------------------------------------------------
