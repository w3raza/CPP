
//
// To jest przyk�adowy kod z podrozdzia�u 8.2.2 �Deklaracje sta�ych i zmiennych� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"     // W tym pliku znajduje si� deklaracja strumienia cout.

//------------------------------------------------------------------------------

int main()
{
    int a;               // Brak inicjatora.
    double d = 7;        // Inicjator okre�lony za pomoc� operatora =.
    vector<int> vi(10);  // Inicjator okre�lony za pomoc� sk�adni ().

    const int x = 7;     // Inicjator okre�lony za pomoc� operatora =.
    const int x2(9);     // initializer using the () syntax
    //const int y;       // B��d: brak inicjatora.
}

//------------------------------------------------------------------------------

namespace innocent
{
    void f(int z)
    {
        int x;           // Niezainicjowany
        // � tutaj nie ma instrukcji przypisuj�cej zmiennej x warto�� �
        x = 7;           // nadanie x warto�ci
        // ...
    }
}

//------------------------------------------------------------------------------

namespace dangerous
{
    void f(int z)
    {
        int x;           // Niezainicjowany
        // � tutaj nie ma instrukcji przypisuj�cej zmiennej x warto�� �
        if (z>x) {    
            // ...
        }
        // ...
        x = 7;           // nadanie x warto�ci
        // ...
    }
}

//------------------------------------------------------------------------------
