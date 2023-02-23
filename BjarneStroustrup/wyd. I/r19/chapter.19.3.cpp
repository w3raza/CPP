
//
// To jest przyk³adowy kod z podrozdzia³u 19.3 „Szablony” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

//------------------------------------------------------------------------------

class Window;

struct Record
{
    int  a;
    char b;
};

//------------------------------------------------------------------------------

int main()
{
    vector<double>           v1;
    vector<int>              v2;
    vector<Month>            v3;
    vector<Window*>          v4;  // Wektor wskaŸników na okna.
    vector< vector<Record> > v5;  // Wektor wektorów obiektów typu Record.
    vector<char>             v6;
}

//------------------------------------------------------------------------------
