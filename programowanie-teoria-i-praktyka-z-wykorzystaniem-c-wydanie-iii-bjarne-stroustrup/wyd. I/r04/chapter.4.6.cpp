
//
// Przyk�adowy kod z rozdzia�u 4.6 "Wektor" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(6); // Wektor zawieraj�cy sze�� liczb ca�kowitych.

    v[0] = 5; 
    v[1] = 7;
    v[2] = 9;
    v[3] = 4;
    v[4] = 6;
    v[5] = 8;


    vector<string> philosopher(4); // Wektor zawieraj�cy cztery �a�cuchy.

    philosopher [0] = "Kant"; 
    philosopher [1] = "Plato";
    philosopher [2] = "Hume";
    philosopher [3] = "Kierkegaard";

    //philosopher[2] = 99;    // B��d: pr�ba przypisania typu int do typu string.
    //v[2] = "Hume";          // B��d: pr�ba przypisania typu string do typu int.

    vector<double> vd(1000,-1.2); // Wektor zawieraj�cy tysi�c element�w typu double zainicjowanych warto�ci� �1.2.

    //vd[20000] = 4.7;        // b��d czasu wykonania
}

//------------------------------------------------------------------------------
