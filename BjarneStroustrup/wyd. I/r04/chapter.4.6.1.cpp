
//
// Przyk³adowy kod z rozdzia³u 4.6.1 "Powiêkszanie wektora" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<double> v;    // Na pocz¹tku wektor jest pusty. Tzn. wektor v nie ma ¿adnych elementów.

    v.push_back(2.7);    // Dodanie elementu o wartoœci 2.7 na koñcu wektora v
                         // Teraz wektor v ma jeden element — v[0]==2.7.

    v.push_back(5.6);    // Dodanie elementu o wartoœci 5.6 na koñcu wektora v.
                         // Teraz wektor v ma dwa elementy, przy czym v[1]==5.6.

    v.push_back(7.9);    // Dodanie elementu o wartoœci 7.9 na koñcu wektora v.
                         // Teraz wektor v ma trzy wartoœci, przy czym v[2]==7.9.

    for(int i=0; i<v.size(); ++i)
        cout << "v[" << i << "]==" <<v[i] << '\n'; 
}

//------------------------------------------------------------------------------
