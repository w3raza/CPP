
//
// To jest przyk³adowy kod z podrozdzia³u 23.8.7 „B³êdy w wyra¿eniach regularnych” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

//------------------------------------------------------------------------------

void wrong_patterns()
{
    regex pat1("(|ghi)");    // brakuje alternatywy
    regex pat2("[c-a]");     // nie przedzia³
}

//------------------------------------------------------------------------------

// wzorzec i zestaw wierszy zostaj¹ przyjête na wejœciu,
// wzorzec zostaje sprawdzony i nastêpuje wyszukanie odpowiadaj¹cych mu wierszy.

int main()
{
    regex pattern;

    string pat;
    cout << "WprowadŸ wzorzec: ";
    getline(cin,pat);        // wczytuje wzorzec

    try {
        pattern = pat;       // sprawdza pat
        cout << "Wzorzec: " << pattern << '\n';
    }
    catch (bad_expression) {
        cout << pat << " nie jest poprawnym wyra¿eniem regularnym.\n";
        exit(1);
    }

    cout << "WprowadŸ tekst:\n";
    string line;             // bufor wejœciowy
    int lineno = 0;

    while (getline(cin,line)) {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pattern)) {
            cout << "Wiersz " << lineno << ": " << line << '\n';
            for (int i = 0; i<matches.size(); ++i)
                cout << "\tpasuje[" << i << "]: "
                     <<  matches[i]  << '\n';
        }
        else
            cout << "nie pasuje\n";
    }
}

//------------------------------------------------------------------------------
