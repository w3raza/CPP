
//
// To jest przyk�adowy kod z podrozdzia�u 18.3 �Podstawowe operacje� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    string s("Triumph");           // Inicjuje s �a�cuchem znak�w "Triumph".
    vector<double> v(10);          // Tworzy wektor 10 liczb typu double o nazwie v.

    vector<double> vi(10);          // Wektor 10 liczb typu double, z kt�rych ka�da zostanie zainicjowana warto�ci� 0.0.
    vector<string> vs(10);         // Wektor 10 �a�cuch�w, z kt�rych ka�dy zostanie zainicjowany warto�ci� "".
    vector<vector< int> > vvi(10); // Wektor 10 wektor�w, z kt�rych ka�dy zostanie zainicjowany warto�ci� vector().
}

//------------------------------------------------------------------------------
