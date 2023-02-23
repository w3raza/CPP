
//
// Przyk�adowy kod z rozdzia�u 4.6.1 "Powi�kszanie wektora" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<double> v;    // Na pocz�tku wektor jest pusty. Tzn. wektor v nie ma �adnych element�w.

    v.push_back(2.7);    // Dodanie elementu o warto�ci 2.7 na ko�cu wektora v
                         // Teraz wektor v ma jeden element � v[0]==2.7.

    v.push_back(5.6);    // Dodanie elementu o warto�ci 5.6 na ko�cu wektora v.
                         // Teraz wektor v ma dwa elementy, przy czym v[1]==5.6.

    v.push_back(7.9);    // Dodanie elementu o warto�ci 7.9 na ko�cu wektora v.
                         // Teraz wektor v ma trzy warto�ci, przy czym v[2]==7.9.

    for(int i=0; i<v.size(); ++i)
        cout << "v[" << i << "]==" <<v[i] << '\n'; 
}

//------------------------------------------------------------------------------
