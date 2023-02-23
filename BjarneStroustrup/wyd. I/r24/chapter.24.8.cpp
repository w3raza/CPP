
//
// To jest przyk³adowy kod z podrozdzia³u 24.8 „Standardowe funkcje matematyczne” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <limits>
#include <cmath>
#include <cerrno>

using namespace std;

//------------------------------------------------------------------------------

const double very_large = std::numeric_limits<double>::max();

int main()
{
    errno = 0;
    double s2 = sqrt(-1.0);
    if (errno) cerr << "Coœ, gdzieœ siê czemuœ nie uda³o.";
    if (errno == EDOM)    // b³¹d dziedziny
        cerr << "Funkcja sqrt() nie przyjmuje ujemnych argumentów.";
    pow(very_large,2);    // Z³y pomys³.
    if (errno==ERANGE)    // B³¹d zakresu.
        cerr << "Wartoœæ pow(" << very_large << ",2) za du¿a dla typu double.";

}

//------------------------------------------------------------------------------
