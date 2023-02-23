
//
// To jest przyk³adowy kod z podrozdzia³u 23.7 „Wyszukiwanie przy u¿yciu wyra¿eñ regularnych” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <boost/regex.hpp>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------

int main()
try
{
    ifstream in("file.txt");    // plik wejœciowy
    if (!in) cerr << "no file\n";

    boost::regex pat ("\\w{2}\\s*\\d{5}(-\\d{4})?");    // wzorzec kodu pocztowego
    cout << "Wzorzec: " << pat << '\n';

    int lineno = 0;
    string line;    // bufor wejœciowy
    while (getline(in,line)) {
        ++lineno;
        boost::smatch matches;    // Tu s¹ zapisywane pasuj¹ce ³añcuchy.
        if (boost::regex_search(line, matches, pat)) {
            cout << lineno << ": " << matches[0] << '\n';
            if (1<matches.size() && matches[1].matched)
                cout  << "\t: " << matches[1] << '\n';    // poddopasowanie
        }
    }
}
catch (std::exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
};

//------------------------------------------------------------------------------
