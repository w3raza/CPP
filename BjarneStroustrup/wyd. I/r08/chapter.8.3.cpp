
//
// To jest przyk�adowy kod z podrozdzia�u 8.3 "Pliki nag��wkowe" ksi��ki 
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
