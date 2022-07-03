
//
// To jest przyk³adowy kod z podrozdzia³u 8.4 „Zakres” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f()
{
    //g();       // B³¹d: funkcja g() nie jest jeszcze w zasiêgu.
}

//------------------------------------------------------------------------------

void g()
{
    f();         // Dobrze: funkcja f() jest w zasiêgu.
}

//------------------------------------------------------------------------------

void h()
{
    //int x = y; // B³¹d: y nie jest jeszcze w zasiêgu.
    int x = 0;
    int y = x;   // Dobrze: x jest w zasiêgu.
    g();         // Dobrze: g() jest w zasiêgu.
}

//------------------------------------------------------------------------------

int main()
{
    h();
}

//------------------------------------------------------------------------------
