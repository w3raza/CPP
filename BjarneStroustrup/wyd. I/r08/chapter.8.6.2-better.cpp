
//
// To jest przyk³adowy kod z podrozdzia³u 8.6.2 „Globalna inicjacja” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

struct Date
{
    Date(int y, int m, int d) { /*...*/ }
};

//------------------------------------------------------------------------------

namespace good
{
    const Date default_date(1970,1,1);    // Domyœlna data to 1 stycznia 1970.
}

//------------------------------------------------------------------------------

namespace better
{
    const Date default_date()             // Zwraca domyœln¹ datê.
    {
        return Date(1970,1,1);
    }
}

//------------------------------------------------------------------------------

namespace best
{
    const Date& default_date()
    {
        static const Date dd(1970,1,1);   // Inicjuje dd przy pierwszym wywo³aniu funkcji.
        return dd;
    }
}

//------------------------------------------------------------------------------

int main()
{
    Date d1 = good::default_date;
    Date d2 = better::default_date();
    Date d3 = best::default_date();
}

//------------------------------------------------------------------------------
