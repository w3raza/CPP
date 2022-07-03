
//
// To jest przyk³adowy kod z podrozdzia³u 8.3 „Pliki nag³ówkowe” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "f.h"

//------------------------------------------------------------------------------

int g(int i)
{
    return f(i);
}

//------------------------------------------------------------------------------

int main()
{
    return g(4444);
}

//------------------------------------------------------------------------------

int f(int n)
{
    return n;
}

//------------------------------------------------------------------------------
