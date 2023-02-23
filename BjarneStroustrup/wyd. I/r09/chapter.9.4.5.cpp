
//
// To jest przyk�adowy kod z podrozdzia�u 9.4.5 "Odwo�ywanie si� do bie��cego obiektu" ksi��ki 
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
    int y, m, d;        // Rok, miesi�c, dzie�
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
