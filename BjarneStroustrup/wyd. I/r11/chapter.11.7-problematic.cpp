
//
// To jest przyk³adowy kod z podrozdzia³u 11.7 „Stosowanie niestandardowych separatorów” ksi¹¿ki 
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

    stringstream ss(line);        // Zmusza strumieñ istream ss do wczytania danych ze zmiennej line.
    vector<string> vs;
    string word;
    while (ss>>word)            // Wczytuje s³owa bez znaków interpunkcyjnych.
        vs.push_back(word);
}

//------------------------------------------------------------------------------
