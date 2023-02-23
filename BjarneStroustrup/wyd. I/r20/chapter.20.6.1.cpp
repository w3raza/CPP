
//
// To jest przyk³adowy kod z podrozdzia³u 20.6.1 „Wiersze” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef vector<char> Line;    // Wiersz jest wektorem znaków.

//------------------------------------------------------------------------------

struct Document {
    list<Line> line;    // Dokument jest list¹ wierszy.
    Document() { line.push_back(Line()); }
};

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Document& d)
{
    char ch;
    while (is>>ch) {
        d.line.back().push_back(ch);    // dodaje znak
        if (ch=='\n') {
            d.line.push_back(Line());   // dodaje wiersz
        }
    }
    return is;
}

//------------------------------------------------------------------------------

int main()
{
    Document d;
    cin >> d;
}

//------------------------------------------------------------------------------
