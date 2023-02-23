
//
// To jest przyk³adowy kod z podrozdzia³u 8.2.3 "Domyœlna inicjacja" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"     // W tym pliku znajduje siê deklaracja strumienia cout.

//------------------------------------------------------------------------------

int main()
{
    vector<string> v; 
    string s;
    while (cin>>s) v.push_back(s);
}

//------------------------------------------------------------------------------
