
//
// To jest przyk�adowy kod z podrozdzia�u 21.7.3 �Utrzymywanie porz�dku przy u�yciu kontenera set� ksi��ki
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
    cin >> from >> to; // Pobiera nazwy plik�w �r�d�owego i docelowego.

    ifstream is(from.c_str()); // Tworzy strumie� wej�ciowy.
    ofstream os(to.c_str());   // Tworzy strumie� wyj�ciowy.

    istream_iterator<string> ii(is);     // Tworzy iterator wej�ciowy dla strumienia.
    istream_iterator<string> eos;        // wartownik wej�cia
    ostream_iterator<string> oo(os," "); // Tworzy iterator wyj�ciowy dla strumienia.

    set<string> b(ii,eos);        // b jest zbiorem inicjowanym przez dane wej�ciowe.
    copy(b.begin() ,b.end() ,oo); // Kopiuje zawarto�� bufora na wyj�cie.
}


//------------------------------------------------------------------------------
