
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.3 "Ukrywanie szczegó³ów" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date.
// Gwarantuje inicjacjê za pomoc¹ konstruktora.
// Wprowadza pewne udogodnienia notacyjne.
struct Date {
    int y, m, d;                // Rok, miesi¹c, dzieñ
    Date(int y, int m, int d);  // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    void add_day(int n);        // Zwiêksza Date o n dni.
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {}

int main()
{
    Date birthday(1960,12,31);  // 31 grudnia 1960
    ++birthday.d;               // Nieprawid³owa data!

    Date today(1970,2,3);
    today.m = 14;               // Nieprawid³owa data!
}

//------------------------------------------------------------------------------
