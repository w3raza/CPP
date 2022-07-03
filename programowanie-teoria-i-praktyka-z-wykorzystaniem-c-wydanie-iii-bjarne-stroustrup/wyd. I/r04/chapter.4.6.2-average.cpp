
//
// Przyk�adowy kod z rozdzia�u 4.6.2 "Przyk�ad wczytywania liczb do programu" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Oblicza �redni� i median� temperatur.
int main()
{
    vector<double> temps;        // temperatury
    double temp;
    while (cin>>temp)            // wczytywanie 
        temps.push_back(temp);   // wstawianie do wektora

    // Obliczanie �redniej temperatury:
    double sum = 0;
    for (int i = 0; i< temps.size(); ++i) sum += temps[i];
    cout << "�rednia temperatura: " << sum/temps.size() << endl;

    // Obliczanie mediany temperatury:
    sort(temps.begin(),temps.end()); // Sortowanie wektora temps "od pocz�tku do ko�ca".
    cout << "Mediana: " << temps[temps.size()/2] << endl;
}

//------------------------------------------------------------------------------
