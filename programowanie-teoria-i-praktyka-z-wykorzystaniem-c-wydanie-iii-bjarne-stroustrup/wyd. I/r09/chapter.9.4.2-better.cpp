
//
// To jest przyk�adowy kod z podrozdzia�u 9.4.2 �Funkcje sk�adowe i konstruktory� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date.
// Gwarantuje inicjacj� za pomoc� konstruktora.
// Wprowadza pewne udogodnienia notacyjne.
struct Date {
    int y, m, d;                        // Rok, miesi�c, dzie�
    Date(int y, int m, int d);          // Sprawdza poprawno�� daty i wykonuje inicjacj�.
    void add_day(int n);                // Zwi�ksza Date o n dni.
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}
void Date::add_day(int n) {}

//------------------------------------------------------------------------------

int main()
{
    //Date my_birthday;                 // B��d: nie zainicjowano my_birthday.
    Date today(12,24,2007);             // B��d czasu wykonania!
    Date last(2000, 12, 31);            // OK (styl potoczny)
    Date christmas = Date(1976,12,24);  // OK (styl rozwlek�y)

    // U�ycie nowo zdefiniowanych zmiennych:

    last.add_day(1);
    //add_day(2);                       // B��d: jaki dzie�?
}

//------------------------------------------------------------------------------
