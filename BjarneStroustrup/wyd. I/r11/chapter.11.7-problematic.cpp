
//
// To jest przyk�adowy kod z podrozdzia�u 11.7 �Stosowanie niestandardowych separator�w� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    string line;
    getline(cin,line);            // Wczytuje do zmiennej line.
    for (int i=0; i<line.size(); ++i) // Zamienia znaki interpunkcyjne na spacje.
        switch(line[i]) {
        case ';': case '.': case ',': case '?': case '!':
            line[i] = ' ';
    }

    stringstream ss(line);        // Zmusza strumie� istream ss do wczytania danych ze zmiennej line.
    vector<string> vs;
    string word;
    while (ss>>word)            // Wczytuje s�owa bez znak�w interpunkcyjnych.
        vs.push_back(word);
}

//------------------------------------------------------------------------------
