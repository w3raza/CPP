
//
// To jest przyk�adowy kod z podrozdzia�u 9.4.4 �Definiowanie funkcji sk�adowych� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date (niekt�rzy wol�, aby szczeg�y implementacyjne by�y na ko�cu).
class Date {
public:
    Date(int y, int m, int d); // Konstruktor: sprawdza, czy data jest poprawna, i wykonuje inicjacj�.
    void add_day(int n);       // Zwi�ksza Date o n dni.
    int month() { return m; }
    // ...
private:
    int y, m, d;               // Rok, miesi�c, dzie�
};

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd) // Konstruktor
        :y(yy), m(mm), d(dd)       // Uwaga: inicjatory sk�adowych.
{
}

//------------------------------------------------------------------------------

void Date::add_day(int n)
{ 
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    {
        int x;              // Najpierw definicja zmiennej x.
        // ...
        x = 2;              // P�niej przypisanie do x.
    }

    {
        int x = 2;          // Definicja i natychmiastowa inicjacja zmiennej warto�ci� 2.
    }

    {
        int x(2);           // Inicjacja x warto�ci� 2.
    }

    Date sunday(2004,8,29); // Inicjacja sunday warto�ci� (2004,8,29).

    sunday.add_day(7);      // Przeskakuje 7 dni.
    return sunday.month();  // Pobiera miesi�c niedzieli.
}

//------------------------------------------------------------------------------
