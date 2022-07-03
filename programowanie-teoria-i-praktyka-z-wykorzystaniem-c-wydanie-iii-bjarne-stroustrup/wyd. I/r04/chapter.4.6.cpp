
//
// Przyk³adowy kod z rozdzia³u 4.6 "Wektor" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<int> v(6); // Wektor zawieraj¹cy szeœæ liczb ca³kowitych.

    v[0] = 5; 
    v[1] = 7;
    v[2] = 9;
    v[3] = 4;
    v[4] = 6;
    v[5] = 8;


    vector<string> philosopher(4); // Wektor zawieraj¹cy cztery ³añcuchy.

    philosopher [0] = "Kant"; 
    philosopher [1] = "Plato";
    philosopher [2] = "Hume";
    philosopher [3] = "Kierkegaard";

    //philosopher[2] = 99;    // B³¹d: próba przypisania typu int do typu string.
    //v[2] = "Hume";          // B³¹d: próba przypisania typu string do typu int.

    vector<double> vd(1000,-1.2); // Wektor zawieraj¹cy tysi¹c elementów typu double zainicjowanych wartoœci¹ –1.2.

    //vd[20000] = 4.7;        // b³¹d czasu wykonania
}

//------------------------------------------------------------------------------
