
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.5 "Odwo³ywanie siê do bie¿¹cego obiektu" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

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
    int y, m, d;        // Rok, miesi¹c, dzieñ
};

//------------------------------------------------------------------------------

void f(Date d1, Date d2)
{
    cout << d1.month() << ' ' << d2.month() << '\n';
}

//------------------------------------------------------------------------------

int main()
{
    Date a(1994,03,29);
    Date b(2000,02,15);

    f(a,b);
    return 0;
}

//------------------------------------------------------------------------------
