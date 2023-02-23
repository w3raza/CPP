
//
// To jest przyk³adowy kod z podrozdzia³u 8.2.2 „Deklaracje sta³ych i zmiennych” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"     // W tym pliku znajduje siê deklaracja strumienia cout.

//------------------------------------------------------------------------------

int main()
{
    int a;               // Brak inicjatora.
    double d = 7;        // Inicjator okreœlony za pomoc¹ operatora =.
    vector<int> vi(10);  // Inicjator okreœlony za pomoc¹ sk³adni ().

    const int x = 7;     // Inicjator okreœlony za pomoc¹ operatora =.
    const int x2(9);     // initializer using the () syntax
    //const int y;       // B³¹d: brak inicjatora.
}

//------------------------------------------------------------------------------

namespace innocent
{
    void f(int z)
    {
        int x;           // Niezainicjowany
        // … tutaj nie ma instrukcji przypisuj¹cej zmiennej x wartoœæ …
        x = 7;           // nadanie x wartoœci
        // ...
    }
}

//------------------------------------------------------------------------------

namespace dangerous
{
    void f(int z)
    {
        int x;           // Niezainicjowany
        // … tutaj nie ma instrukcji przypisuj¹cej zmiennej x wartoœæ …
        if (z>x) {    
            // ...
        }
        // ...
        x = 7;           // nadanie x wartoœci
        // ...
    }
}

//------------------------------------------------------------------------------
