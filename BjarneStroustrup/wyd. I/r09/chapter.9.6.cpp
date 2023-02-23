
//
// To jest przyk�adowy kod z podrozdzia�u 9.6 �Przeci��anie operator�w� ksi��ki 
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
    m = (m==dcm) ? jan : Month(m+1);             // �zawini�cie�
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

//int operator+(int,int);        // B��d: nie mo�na przeci��y� wbudowanego operatora +.
Vector operator+(const Vector&, const Vector &); // ok 
Vector operator+=(const Vector&, int);           // ok

//------------------------------------------------------------------------------

int main()
{
    Month m = sep;
    ++m;                // m dostaje warto�� oct
    ++m;                // m dostaje warto�� nov
    ++m;                // m dostaje warto�� dec
    ++m;                // m dostaje warto�� jan (�zawini�cie�)
    cout << m << endl;
    return 0;
}

//------------------------------------------------------------------------------
