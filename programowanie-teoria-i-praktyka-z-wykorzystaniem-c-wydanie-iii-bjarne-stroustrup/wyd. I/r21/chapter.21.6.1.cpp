
//
// To jest przyk�adowy kod z podrozdzia�u 21.6.1 �S�owniki� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    map<string,int> words;    // Przechowuje pary (klucz,warto��).

    string s;
    while (cin>>s) ++words[s];       // Uwaga: s�ownik words jest indkesowany �a�cuchem.

    typedef map<string,int>::const_iterator Iter;
    for (Iter  p = words.begin(); p!=words.end(); ++p)
        cout << p->first << ": " << p->second << '\n';
}

//------------------------------------------------------------------------------
