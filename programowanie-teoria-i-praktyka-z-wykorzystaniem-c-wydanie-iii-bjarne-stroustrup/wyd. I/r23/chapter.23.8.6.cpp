
//
// To jest przyk�adowy kod z podrozdzia�u 23.8.6 �Zbiory i przedzia�y znak�w� ksi��ki
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

    // Dodatkowo trzeba zastosowa� symbole zast�pcze dla uko�nik�w

    regex r("\\\"[[:alnum:]]+\\\"");
}
catch (std::exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
};

//------------------------------------------------------------------------------
