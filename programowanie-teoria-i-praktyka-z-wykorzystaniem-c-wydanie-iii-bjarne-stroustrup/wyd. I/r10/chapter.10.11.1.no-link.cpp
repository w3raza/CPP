
//
// To jest przyk³adowy kod z podrozdzia³u 10.11.1 „Reprezentacja danych w pamiêci” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

using namespace std;

//------------------------------------------------------------------------------

const int not_a_reading = -7777;    // Mniej ni¿ zero bezwzglêdne.
const int not_a_month = -1;

//------------------------------------------------------------------------------

struct Day {
    vector<double> hour;
    Day();                // Inicjacja godzin wartoœci¹ „nieodczyt”.
};

//------------------------------------------------------------------------------

Day::Day() : hour(24)
{
    for (int i = 0; i<hour.size(); ++i) hour[i]=not_a_reading;
}

//------------------------------------------------------------------------------

struct Month {            // Miesi¹c pomiarów temperatury.
    int month;            // <0,11>, styczeñ == 0.
    vector<Day> day;      // <1,31>, jeden wektor odczytów na dzieñ.
    Month()               // W miesi¹cu mo¿e byæ najwy¿ej 31 dni (zmarnowany element day[0]).
        :month(not_a_month), day(32) { }
};

//------------------------------------------------------------------------------

struct Year {             // Rok wyników pomiarów temperatury, zorganizowany wed³ug miesiêcy.
    int year;             // Liczba dodatnia == rok.
    vector<Month> month;  // <0,11>, styczeñ == 0.
    Year() :month(12) { } // W roku jest 12 miesiêcy.
};

//------------------------------------------------------------------------------
