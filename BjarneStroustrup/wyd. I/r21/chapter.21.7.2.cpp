
//
// To jest przyk�adowy kod z podrozdzia�u 21.7.2 �Iteratory strumieni� ksi��ki
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
    ostream_iterator<string> oo(cout);        // Przypisanie do *oo jest r�wnowa�ne z zapisem w cout.

    *oo = "Witaj, ";    // Oznacza cout << "Witaj, "
    ++oo;               // Przygotowanie do nast�pnej operacji wyj�ciowej.
    *oo = "�wiecie!\n";   // Oznacza cout << "�wiecie!\n".

    istream_iterator<string> ii(cin); // reading *ii is to read a string from cin

    string s1 = *ii;    // Oznacza cin>>s1.
    ++ii;               // Przygotowanie na nast�pn� operacj� wej�ciow�.
    string s2 = *ii;    // Oznacza cin>>s2.
}

//------------------------------------------------------------------------------

int main()
{
    string from, to;
    cin >> from >> to;  // Pobiera nazwy plik�w �r�d�owego i docelowego.

    ifstream is(from.c_str());            // Otwiera strumie� wej�ciowy.
    ofstream os(to.c_str());              // Otwiera strumie� wyj�ciowy.

    istream_iterator<string> ii(is);      // Tworzy iterator wej�ciowy dla strumienia.
    istream_iterator<string> eos;         // wartownik wej�cia
    ostream_iterator<string> oo(os,"\n"); // Tworzy iterator wyj�ciowy dla strumienia.

    vector<string> b(ii,eos);             // b jest wektorem inicjowanym danymi wej�ciowymi.
    sort(b.begin() ,b.end());             // sortuje bufor
    copy(b.begin() ,b.end() ,oo);         // Kopiuje zawarto�� bufora na wyj�cie.

}

//------------------------------------------------------------------------------
