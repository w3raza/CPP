
//
// To jest przyk³adowy kod z podrozdzia³u 21.6.1 „S³owniki” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    map<string,int> words;    // Przechowuje pary (klucz,wartoœæ).

    string s;
    while (cin>>s) ++words[s];       // Uwaga: s³ownik words jest indkesowany ³añcuchem.

    typedef map<string,int>::const_iterator Iter;
    for (Iter  p = words.begin(); p!=words.end(); ++p)
        cout << p->first << ": " << p->second << '\n';
}

//------------------------------------------------------------------------------
