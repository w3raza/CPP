
//
// To jest przyk³adowy kod z podrozdzia³u 18.3 „Podstawowe operacje” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    string s("Triumph");           // Inicjuje s ³añcuchem znaków "Triumph".
    vector<double> v(10);          // Tworzy wektor 10 liczb typu double o nazwie v.

    vector<double> vi(10);          // Wektor 10 liczb typu double, z których ka¿da zostanie zainicjowana wartoœci¹ 0.0.
    vector<string> vs(10);         // Wektor 10 ³añcuchów, z których ka¿dy zostanie zainicjowany wartoœci¹ "".
    vector<vector< int> > vvi(10); // Wektor 10 wektorów, z których ka¿dy zostanie zainicjowany wartoœci¹ vector().
}

//------------------------------------------------------------------------------
