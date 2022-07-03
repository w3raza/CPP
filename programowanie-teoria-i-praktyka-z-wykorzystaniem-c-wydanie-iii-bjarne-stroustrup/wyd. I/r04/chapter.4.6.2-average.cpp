
//
// Przyk³adowy kod z rozdzia³u 4.6.2 "Przyk³ad wczytywania liczb do programu" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Oblicza œredni¹ i medianê temperatur.
int main()
{
    vector<double> temps;        // temperatury
    double temp;
    while (cin>>temp)            // wczytywanie 
        temps.push_back(temp);   // wstawianie do wektora

    // Obliczanie œredniej temperatury:
    double sum = 0;
    for (int i = 0; i< temps.size(); ++i) sum += temps[i];
    cout << "Œrednia temperatura: " << sum/temps.size() << endl;

    // Obliczanie mediany temperatury:
    sort(temps.begin(),temps.end()); // Sortowanie wektora temps "od pocz¹tku do koñca".
    cout << "Mediana: " << temps[temps.size()/2] << endl;
}

//------------------------------------------------------------------------------
