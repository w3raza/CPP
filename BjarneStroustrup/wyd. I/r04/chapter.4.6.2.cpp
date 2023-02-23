
//
// Przyk³adowy kod z rozdzia³u 4.6.2 "Przyk³ad wczytywania liczb do programu" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Wczytuje wartoœci temperatur do wektora.
int main()
{
    vector<double> temps;         // temperatury
    double temp;
    while (cin>>temp)             // wczytywanie 
        temps.push_back(temp);    // wstawianie do wektora
    // ... przetwarzanie ...
}

//------------------------------------------------------------------------------
