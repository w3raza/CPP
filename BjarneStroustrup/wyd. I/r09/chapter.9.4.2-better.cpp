
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.2 „Funkcje sk³adowe i konstruktory” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date.
// Gwarantuje inicjacjê za pomoc¹ konstruktora.
// Wprowadza pewne udogodnienia notacyjne.
struct Date {
    int y, m, d;                        // Rok, miesi¹c, dzieñ
    Date(int y, int m, int d);          // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    void add_day(int n);                // Zwiêksza Date o n dni.
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}
void Date::add_day(int n) {}

//------------------------------------------------------------------------------

int main()
{
    //Date my_birthday;                 // B³¹d: nie zainicjowano my_birthday.
    Date today(12,24,2007);             // B³¹d czasu wykonania!
    Date last(2000, 12, 31);            // OK (styl potoczny)
    Date christmas = Date(1976,12,24);  // OK (styl rozwlek³y)

    // U¿ycie nowo zdefiniowanych zmiennych:

    last.add_day(1);
    //add_day(2);                       // B³¹d: jaki dzieñ?
}

//------------------------------------------------------------------------------
