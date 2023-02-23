
//
// To jest przyk�adowy kod z podrozdzia�u 10.11.1 �Reprezentacja danych w pami�ci� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

const int not_a_reading = -7777;    // Mniej ni� zero bezwzgl�dne.
const int not_a_month = -1;

//------------------------------------------------------------------------------

struct Day {
    vector<double> hour;
    Day();                // Inicjacja godzin warto�ci� �nieodczyt�.
};

//------------------------------------------------------------------------------

Day::Day() : hour(24)
{
    for (int i = 0; i<hour.size(); ++i) hour[i]=not_a_reading;
}

//------------------------------------------------------------------------------

struct Month {            // Miesi�c pomiar�w temperatury.
    int month;            // <0,11>, stycze� == 0.
    vector<Day> day;      // <1,31>, jeden wektor odczyt�w na dzie�.
    Month()               // W miesi�cu mo�e by� najwy�ej 31 dni (zmarnowany element day[0]).
        :month(not_a_month), day(32) { }
};

//------------------------------------------------------------------------------

struct Year {             // Rok wynik�w pomiar�w temperatury, zorganizowany wed�ug miesi�cy.
    int year;             // Liczba dodatnia == rok.
    vector<Month> month;  // <0,11>, stycze� == 0.
    Year() :month(12) { } // W roku jest 12 miesi�cy.
};

//------------------------------------------------------------------------------
