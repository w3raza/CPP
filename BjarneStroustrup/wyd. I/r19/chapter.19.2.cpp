
//
// To jest przyk³adowy kod z podrozdzia³u 19.2 „Zmienianie rozmiaru” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    int n = 100;
    vector<double> v(n); // v.size()==n
    
    // Rozmiar mo¿na zmieniæ na trzy sposoby:
    
    v.resize(10);         // v zawiera teraz 10 elementów.
    
    v.push_back(7);      // Dodaje element o wartoœci 7 na koñcu v.
                         // v.size() zwiêksza siê o 1.

    vector<double> v2(7);// v.size()==7
    v = v2;              // Przypisanie innego wektora. v jest teraz kopi¹ v2.
                         // v.size() teraz równa siê v2.size()
}

//------------------------------------------------------------------------------
