
//
// Przyk�adowy kod z rozdzia�u 5.7 "B��dy logiczne" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    double temp = 0;
    double sum = 0;
    double high_temp = -1000;  // Inicjacja zmiennej ujemn� warto�ci� niemo�liw� do osi�gni�cia.
    double low_temp  =  1000;  // Inicjacja zmiennej dodatni� warto�ci� niemo�liw� do osi�gni�cia.
    int no_of_temps  =  0;

    while (cin>>temp) {        // wczytywanie danych
        ++no_of_temps;         // zliczanie temperatur
        sum += temp;           // obliczanie sumy
        if (temp > high_temp) high_temp = temp;  // Znajduje najwy�sz� temperatur�.
        if (temp < low_temp)  low_temp  = temp;  // Znajduje najni�sz� temperatur�.
    }

    cout << "Najwy�sza temperatura: " << high_temp<< endl;
    cout << "Najni�sza temperatura: " << low_temp << endl;
    cout << "�rednia temperatura: " << sum/no_of_temps << endl;
}

//------------------------------------------------------------------------------
