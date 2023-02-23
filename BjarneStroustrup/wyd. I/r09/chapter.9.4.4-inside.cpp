
//
// To jest przyk�adowy kod z podrozdzia�u 9.4.4 "Definiowanie funkcji sk�adowych" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date (niekt�rzy wol�, aby szczeg�y implementacyjne by�y na ko�cu).
class Date {
public:
    Date(int yy, int mm, int dd) 
        :y(yy), m(mm), d(dd)        
    {
        // ...
    }

    void add_day(int n)
    {
        // ...
    }

    int month() { return m; }

    // ...
private:
    int y, m, d;            // Rok, miesi�c, dzie�
};

//------------------------------------------------------------------------------

int main()
{
    Date sunday(2004,8,29); // Inicjacja sunday warto�ci� (2004,8,29).
    sunday.add_day(7);      // Przeskakuje 7 dni.
    return sunday.month();  // Pobiera miesi�c niedzieli.
}

//------------------------------------------------------------------------------
