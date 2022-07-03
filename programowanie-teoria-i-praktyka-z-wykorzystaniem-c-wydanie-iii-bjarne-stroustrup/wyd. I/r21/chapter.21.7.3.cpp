
//
// To jest przyk³adowy kod z podrozdzia³u 21.7.3 „Utrzymywanie porz¹dku przy u¿yciu kontenera set” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <set>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    string from, to;
    cin >> from >> to; // Pobiera nazwy plików Ÿród³owego i docelowego.

    ifstream is(from.c_str()); // Tworzy strumieñ wejœciowy.
    ofstream os(to.c_str());   // Tworzy strumieñ wyjœciowy.

    istream_iterator<string> ii(is);     // Tworzy iterator wejœciowy dla strumienia.
    istream_iterator<string> eos;        // wartownik wejœcia
    ostream_iterator<string> oo(os," "); // Tworzy iterator wyjœciowy dla strumienia.

    set<string> b(ii,eos);        // b jest zbiorem inicjowanym przez dane wejœciowe.
    copy(b.begin() ,b.end() ,oo); // Kopiuje zawartoœæ bufora na wyjœcie.
}


//------------------------------------------------------------------------------
