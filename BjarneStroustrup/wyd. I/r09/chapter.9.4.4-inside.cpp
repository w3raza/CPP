
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.4 "Definiowanie funkcji sk³adowych" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date (niektórzy wol¹, aby szczegó³y implementacyjne by³y na koñcu).
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
    int y, m, d;            // Rok, miesi¹c, dzieñ
};

//------------------------------------------------------------------------------

int main()
{
    Date sunday(2004,8,29); // Inicjacja sunday wartoœci¹ (2004,8,29).
    sunday.add_day(7);      // Przeskakuje 7 dni.
    return sunday.month();  // Pobiera miesi¹c niedzieli.
}

//------------------------------------------------------------------------------
