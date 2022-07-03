
//
// To jest przyk�adowy kod z podrozdzia�u 8.6.1 �Warto�ciowanie wyra�e� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<int> v(10);                   // v jest zmienn� globaln�.

void f(int i, int j)
{
    cout << i << ' ' << j << '\n';
}

//------------------------------------------------------------------------------

int main()
{
    int i = 4;
    v[i] = ++i;                      // Nie r�b tego: nieokre�lony porz�dek warto�ciowania.
    v[++i] = i;                      // Nie r�b tego: nieokre�lony porz�dek warto�ciowania.
    int x = ++i + ++i;               // Nie r�b tego: nieokre�lony porz�dek warto�ciowania.
    cout << ++i << ' ' << i << '\n'; // Nie r�b tego: nieokre�lony porz�dek warto�ciowania.
    f(++i,++i);                      // Nie r�b tego: nieokre�lony porz�dek warto�ciowania.
}

//------------------------------------------------------------------------------
