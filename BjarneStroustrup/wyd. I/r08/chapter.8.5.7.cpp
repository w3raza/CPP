
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.7 "Sprawdzanie argument�w i konwersja" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

typedef double T;

void f(T x);

int main()
{
    T y = 3.1415;
    f(y);
    T x(y);        // Inicjacja x warto�ci� y (podrozdzia� 8.2.2).
}

//------------------------------------------------------------------------------

void f(double);

void g(int y)
{
    f(y);
    double x(y);
}

//------------------------------------------------------------------------------

void ff(int);

void gg(double x)
{
    ff(x);    // Sk�d wiadomo, czy to ma jaki� sens?
}

//------------------------------------------------------------------------------

void ggg(double x)
{
    int x1 = x;    // przycina x
    int x2 = int(x);

    ff(x1);
    ff(x2);

    ff(x);        // przycina x
    ff(int(x));
}

//------------------------------------------------------------------------------

void f(double) 
{
}

//------------------------------------------------------------------------------

void ff(int) 
{
}

//------------------------------------------------------------------------------
