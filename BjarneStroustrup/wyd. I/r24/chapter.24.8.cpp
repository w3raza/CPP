
//
// To jest przyk�adowy kod z podrozdzia�u 24.8 �Standardowe funkcje matematyczne� ksi��ki
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
    if (errno) cerr << "Co�, gdzie� si� czemu� nie uda�o.";
    if (errno == EDOM)    // b��d dziedziny
        cerr << "Funkcja sqrt() nie przyjmuje ujemnych argument�w.";
    pow(very_large,2);    // Z�y pomys�.
    if (errno==ERANGE)    // B��d zakresu.
        cerr << "Warto�� pow(" << very_large << ",2) za du�a dla typu double.";

}

//------------------------------------------------------------------------------
