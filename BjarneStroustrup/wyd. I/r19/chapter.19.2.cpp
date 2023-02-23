
//
// To jest przyk�adowy kod z podrozdzia�u 19.2 �Zmienianie rozmiaru� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    int n = 100;
    vector<double> v(n); // v.size()==n
    
    // Rozmiar mo�na zmieni� na trzy sposoby:
    
    v.resize(10);         // v zawiera teraz 10 element�w.
    
    v.push_back(7);      // Dodaje element o warto�ci 7 na ko�cu v.
                         // v.size() zwi�ksza si� o 1.

    vector<double> v2(7);// v.size()==7
    v = v2;              // Przypisanie innego wektora. v jest teraz kopi� v2.
                         // v.size() teraz r�wna si� v2.size()
}

//------------------------------------------------------------------------------
