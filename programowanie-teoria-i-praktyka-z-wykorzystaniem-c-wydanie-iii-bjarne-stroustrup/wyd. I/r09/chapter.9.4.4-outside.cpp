
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.4 „Definiowanie funkcji sk³adowych” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prosty typ Date (niektórzy wol¹, aby szczegó³y implementacyjne by³y na koñcu).
class Date {
public:
    Date(int y, int m, int d); // Konstruktor: sprawdza, czy data jest poprawna, i wykonuje inicjacjê.
    void add_day(int n);       // Zwiêksza Date o n dni.
    int month() { return m; }
    // ...
private:
    int y, m, d;               // Rok, miesi¹c, dzieñ
};

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd) // Konstruktor
        :y(yy), m(mm), d(dd)       // Uwaga: inicjatory sk³adowych.
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
        x = 2;              // PóŸniej przypisanie do x.
    }

    {
        int x = 2;          // Definicja i natychmiastowa inicjacja zmiennej wartoœci¹ 2.
    }

    {
        int x(2);           // Inicjacja x wartoœci¹ 2.
    }

    Date sunday(2004,8,29); // Inicjacja sunday wartoœci¹ (2004,8,29).

    sunday.add_day(7);      // Przeskakuje 7 dni.
    return sunday.month();  // Pobiera miesi¹c niedzieli.
}

//------------------------------------------------------------------------------
