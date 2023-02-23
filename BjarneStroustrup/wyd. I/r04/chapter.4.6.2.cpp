
//
// Przyk�adowy kod z rozdzia�u 4.6.2 "Przyk�ad wczytywania liczb do programu" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje warto�ci temperatur do wektora.
int main()
{
    vector<double> temps;         // temperatury
    double temp;
    while (cin>>temp)             // wczytywanie 
        temps.push_back(temp);    // wstawianie do wektora
    // ... przetwarzanie ...
}

//------------------------------------------------------------------------------
