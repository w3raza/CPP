
//
// To jest przyk³adowy kod z podrozdzia³u 8.3 "Pliki nag³ówkowe" ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

int f(int);
int g(int i)
{
    return f(i);
}

//------------------------------------------------------------------------------

int main()
{
    return g(0);
}

//------------------------------------------------------------------------------

int f(int n)
{
    return n;
}

//------------------------------------------------------------------------------
