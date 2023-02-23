
//
// Przyk³adowy kod z rozdzia³u 5.7 "B³êdy logiczne" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    vector<double> temps; // temperatury 

    double temp = 0;
    double sum = 0;
    double high_temp = 0;
    double low_temp  = 0;

    while (cin>>temp)         // Wczytuje i wysy³a do temp.
        temps.push_back(temp);

    for (int i = 0; i<temps.size(); ++i)
    {
        if(temps[i] > high_temp) high_temp = temps[i];  // Znajduje najwy¿sz¹ temperaturê.
        if(temps[i] < low_temp)  low_temp  = temps[i];  // Znajduje najni¿sz¹ temperaturê.
        sum += temps[i];      // oblicza sumê
    }

    cout << "Najwy¿sza temperatura: " << high_temp<< endl;
    cout << "Najni¿sza temperatura: " << low_temp << endl;
    cout << "Œrednia temperatura: " << sum/no_of_temps << endl;
}

//------------------------------------------------------------------------------
