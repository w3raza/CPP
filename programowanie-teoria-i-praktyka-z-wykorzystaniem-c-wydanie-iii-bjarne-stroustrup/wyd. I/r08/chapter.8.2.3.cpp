
//
// To jest przyk�adowy kod z podrozdzia�u 8.2.3 "Domy�lna inicjacja" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"     // W tym pliku znajduje si� deklaracja strumienia cout.

//------------------------------------------------------------------------------

int main()
{
    vector<string> v; 
    string s;
    while (cin>>s) v.push_back(s);
}

//------------------------------------------------------------------------------
