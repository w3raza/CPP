
//
// To jest przyk�adowy kod z podrozdzia�u 8.4 �Zakres� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f()
{
    //g();       // B��d: funkcja g() nie jest jeszcze w zasi�gu.
}

//------------------------------------------------------------------------------

void g()
{
    f();         // Dobrze: funkcja f() jest w zasi�gu.
}

//------------------------------------------------------------------------------

void h()
{
    //int x = y; // B��d: y nie jest jeszcze w zasi�gu.
    int x = 0;
    int y = x;   // Dobrze: x jest w zasi�gu.
    g();         // Dobrze: g() jest w zasi�gu.
}

//------------------------------------------------------------------------------

int main()
{
    h();
}

//------------------------------------------------------------------------------
