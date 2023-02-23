
//
// To jest przyk�adowy kod z podrozdzia�u 21.7.1 �Funkcja copy()� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <vector>

using std::list;
using std::vector;
using std::string;
using std::exception;
using std::runtime_error;
using std::cerr;

//------------------------------------------------------------------------------

namespace our {
    template<class In, class Out> Out copy(In first, In last, Out res)
    {
        while (first!=last) {
            *res = *first;    // kopiuje element
            ++res;
            ++first;
        }
        return res;
    }
}

//------------------------------------------------------------------------------
// Funkcja pomocnicza wy�wietlaj�ca komunikat o b��dzie.
inline void error(const string& errormessage)
{
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------

void f(vector<double>& vd, list<int>& li)
// Kopiuje elementy listy liczb typu int do wektora liczb typu double.
{
    if (vd.size() < li.size()) error("Kontener docelowy jest za ma�y.");
    our::copy(li.begin(), li.end(), vd.begin());    
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<double> v(5);
    list<int> l(5);
    f(v,l);
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
