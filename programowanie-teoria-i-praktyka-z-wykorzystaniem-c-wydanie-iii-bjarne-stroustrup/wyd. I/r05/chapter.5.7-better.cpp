
//
// Przyk³adowy kod z rozdzia³u 5.7 "B³êdy logiczne" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double temp = 0;
    double sum = 0;
    double high_temp = -1000;  // Inicjacja zmiennej ujemn¹ wartoœci¹ niemo¿liw¹ do osi¹gniêcia.
    double low_temp  =  1000;  // Inicjacja zmiennej dodatni¹ wartoœci¹ niemo¿liw¹ do osi¹gniêcia.
    int no_of_temps  =  0;

    while (cin>>temp) {        // wczytywanie danych
        ++no_of_temps;         // zliczanie temperatur
        sum += temp;           // obliczanie sumy
        if (temp > high_temp) high_temp = temp;  // Znajduje najwy¿sz¹ temperaturê.
        if (temp < low_temp)  low_temp  = temp;  // Znajduje najni¿sz¹ temperaturê.
    }

    cout << "Najwy¿sza temperatura: " << high_temp<< endl;
    cout << "Najni¿sza temperatura: " << low_temp << endl;
    cout << "Œrednia temperatura: " << sum/no_of_temps << endl;
}

//------------------------------------------------------------------------------
