
//
// To jest przyk³adowy kod z podrozdzia³u 9.6 „Przeci¹¿anie operatorów” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dcm
};

//------------------------------------------------------------------------------

Month operator++(Month& m)                       // Przedrostkowy operator inkrementacji.
{
    m = (m==dcm) ? jan : Month(m+1);             // „zawiniêcie”
    return m;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, Month m)
{
    static const char* month_tbl[12] = {
        "January","February","March","April","May","June","July",
        "August","September","October","November","December"
    };
    return os << month_tbl[m-1];
}

//------------------------------------------------------------------------------

class Vector {};

//int operator+(int,int);        // B³¹d: nie mo¿na przeci¹¿yæ wbudowanego operatora +.
Vector operator+(const Vector&, const Vector &); // ok 
Vector operator+=(const Vector&, int);           // ok

//------------------------------------------------------------------------------

int main()
{
    Month m = sep;
    ++m;                // m dostaje wartoœæ oct
    ++m;                // m dostaje wartoœæ nov
    ++m;                // m dostaje wartoœæ dec
    ++m;                // m dostaje wartoœæ jan („zawiniêcie”)
    cout << m << endl;
    return 0;
}

//------------------------------------------------------------------------------
