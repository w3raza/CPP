
//
// To jest przyk�adowy kod z podrozdzia�u 19.3 �Szablony� ksi��ki
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
    vector<Window*>          v4;  // Wektor wska�nik�w na okna.
    vector< vector<Record> > v5;  // Wektor wektor�w obiekt�w typu Record.
    vector<char>             v6;
}

//------------------------------------------------------------------------------
