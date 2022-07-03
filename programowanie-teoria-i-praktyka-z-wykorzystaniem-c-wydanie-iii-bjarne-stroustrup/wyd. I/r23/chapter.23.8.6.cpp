
//
// To jest przyk³adowy kod z podrozdzia³u 23.8.6 „Zbiory i przedzia³y znaków” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <boost/regex.hpp>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

//------------------------------------------------------------------------------
using namespace boost;

int main()
try
{
    string s = "\"[[:alnum:]]+\"";

    // Dodatkowo trzeba zastosowaæ symbole zastêpcze dla ukoœników

    regex r("\\\"[[:alnum:]]+\\\"");
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
