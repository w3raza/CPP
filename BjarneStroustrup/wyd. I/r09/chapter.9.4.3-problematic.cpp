
//
// To jest przyk�adowy kod z podrozdzia�u 9.4.3 "Ukrywanie szczeg��w" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date.
// Gwarantuje inicjacj� za pomoc� konstruktora.
// Wprowadza pewne udogodnienia notacyjne.
struct Date {
    int y, m, d;                // Rok, miesi�c, dzie�
    Date(int y, int m, int d);  // Sprawdza poprawno�� daty i wykonuje inicjacj�.
    void add_day(int n);        // Zwi�ksza Date o n dni.
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}

int main()
{
    Date birthday(1960,12,31);  // 31 grudnia 1960
    ++birthday.d;               // Nieprawid�owa data!

    Date today(1970,2,3);
    today.m = 14;               // Nieprawid�owa data!
}

//------------------------------------------------------------------------------
