
//
// To jest przyk³adowy kod z podrozdzia³u 21.7.2 „Iteratory strumieni” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

void foo()
{
    ostream_iterator<string> oo(cout);        // Przypisanie do *oo jest równowa¿ne z zapisem w cout.

    *oo = "Witaj, ";    // Oznacza cout << "Witaj, "
    ++oo;               // Przygotowanie do nastêpnej operacji wyjœciowej.
    *oo = "œwiecie!\n";   // Oznacza cout << "œwiecie!\n".

    istream_iterator<string> ii(cin); // reading *ii is to read a string from cin

    string s1 = *ii;    // Oznacza cin>>s1.
    ++ii;               // Przygotowanie na nastêpn¹ operacjê wejœciow¹.
    string s2 = *ii;    // Oznacza cin>>s2.
}

//------------------------------------------------------------------------------

int main()
{
    string from, to;
    cin >> from >> to;  // Pobiera nazwy plików Ÿród³owego i docelowego.

    ifstream is(from.c_str());            // Otwiera strumieñ wejœciowy.
    ofstream os(to.c_str());              // Otwiera strumieñ wyjœciowy.

    istream_iterator<string> ii(is);      // Tworzy iterator wejœciowy dla strumienia.
    istream_iterator<string> eos;         // wartownik wejœcia
    ostream_iterator<string> oo(os,"\n"); // Tworzy iterator wyjœciowy dla strumienia.

    vector<string> b(ii,eos);             // b jest wektorem inicjowanym danymi wejœciowymi.
    sort(b.begin() ,b.end());             // sortuje bufor
    copy(b.begin() ,b.end() ,oo);         // Kopiuje zawartoœæ bufora na wyjœcie.

}

//------------------------------------------------------------------------------
