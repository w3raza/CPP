
//
// To jest przyk³adowy kod z podrozdzia³u 24.5.2 „Macierze jednowymiarowe” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Matrix.h"

using namespace Numeric_lib;

//------------------------------------------------------------------------------

double f(double a) { return a*a; }

//------------------------------------------------------------------------------

double f2(double a, double b) { return a*b; }

//------------------------------------------------------------------------------

double scale(double d, double s) { return d*s; }

//------------------------------------------------------------------------------

void scale_in_place(double& d, double s) { d *= s; }

//------------------------------------------------------------------------------

int main()
{
    Matrix<int,1> a1(8);          // a1 jest jednowymiarow¹ macierz¹ liczb typu int.
    Matrix<int>   a(8);           // Oznacza Matrix<int,1> a(8);.

    a.size();                     // Liczba elementów w macierzy.
    a.dim1();                     // Liczba elementów w pierwszym wymiarze.

    int  i = 4;
    int  n = 7;
    int* p = a.data();            // Wydobywa dane jako wskaŸnik na tablicê.

    a(i);                         // i-ty element (styl jêzyka Fortran), ale sprawdzany jest zakres.
    a[i];                         // i-ty element (styl jêzyka C), ze sprawdzaniem zakresu.
    //a(1,2);                     // B³¹d: a jest macierz¹ jednowymiarow¹.

    a.slice(i);                   // Elementy od elementu a[i] do koñca.
    a.slice(i,n);                  // n elementów od a[i] do a[i+n–1].

    a.slice(4,4) = a.slice(0,4);  // Przypisuje pierwsz¹ po³owê a do jej drugiej po³owy.
    a.slice(4) = a.slice(0,4);    // Przypisuje pierwsz¹ po³owê a do jej drugiej po³owy.

    Matrix<int> a2 = a;           // inicjowanie kopiuj¹ce
    a = a2;                       // przypisanie kopiuj¹ce
    a *= 7;                       // Skalowanie: a[i]*=7 dla ka¿dego i (tak¿e +=, –=, /=, itp.).
    a = 7;                        // a[i]=7 dla ka¿dego i

    a.apply(f);                   // a[i]=f(a[i]) dla ka¿dego elementu a[i]
    a.apply(f2,7);                // a[i]=f(a[i],7) dla ka¿dego elementu a[i]

    Matrix<int> b = apply(abs,a); // Tworzy now¹ macierz, w której b(i)==abs(a(i)).

    b = a*7;                      // b[i] = a[i]*7 dla ka¿dego i
    a *= 7;                       // a[i] =a[i]*7 dla ka¿dego i
    Matrix<double> x(10);
    Matrix<double> y = apply(f,x);// y[i] =f(x[i]) dla ka¿dego i
    x.apply(f);                   // x[i] =f(x[i]) dla ka¿dego i

    b = apply(f2,a,7);            // b[i]=f(a[i],x) dla ka¿dego i
    b = apply(scale,a,7);         // b[i] = a[i]*7 dla ka¿dego i
    x.apply(scale_in_place,7);    // a[i] *= 7 dla ka¿dego i

    Matrix<int> a3  = scale_and_add(a,8,a2); // Dodawanie i mno¿enie w jednej operacji.
    int r = dot_product(a3,a);               // iloczyn skalarny

}

//------------------------------------------------------------------------------

void some_function(double* p, int n)
{
    double val[] = { 1.2, 2.3, 3.4, 4.5 };
    Matrix<double> data(p,n);
    Matrix<double> constants(val);
    // ...
}

//------------------------------------------------------------------------------
