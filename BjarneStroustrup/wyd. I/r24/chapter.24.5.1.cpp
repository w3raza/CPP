
//
// To jest przyk³adowy kod z podrozdzia³u 24.5.1 „Wymiary i dostêp” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace Numeric_lib;

//------------------------------------------------------------------------------

void f(int n1, int n2, int n3)
{
    Matrix<double,1> ad1(n1);       // Elementy s¹ typu double; jeden wymiar.
    Matrix<int,1>    ai1(n1);       // Elementy s¹ typu int; jeden wymiar.
    ad1(7) = 0;                     // Indeksowanie za pomoc¹ operatora ( ) — styl jêzyka Fortran.
    ad1[7] = 8;                     // Operator [ ] te¿ dzia³a — styl jêzyka C.

    Matrix<double,2> ad2(n1,n2);    // dwa wymiary
    Matrix<double,3> ad3(n1,n2,n3); // trzy wymiary
    ad2(3,4)   = 7.5;               // prawdziwe wielowymiarowe indeksowanie
    ad3(3,4,5) = 9.2;
}

//------------------------------------------------------------------------------

void f1(int n1, int n2, int n3)
{
    //Matrix<int,0> ai0;            // B³¹d: nie ma macierzy 0-wymiarowych.

    Matrix<double,1> ad1(5);
    Matrix<int,1>    ai(5);
    Matrix<double,1> ad11(7); 

    ad1(7) = 0;                     // Wyj¹tek Matrix_error (7 jest poza zakresem).
    //ad1 = ai;                     // B³¹d: ró¿ne typy elementów.
    ad1 = ad11;                     // Wyj¹tek Matrix_error (ró¿ne wymiary).

    //Matrix<double,2>  ad2(n1);    // B³¹d: nie podano rozmiaru drugiego wymiaru.
    //ad2(3) = 7.5;                 // B³¹d: nieprawid³owa liczba indeksów.
    //ad2(1,2,3) = 7.5;             // B³¹d: nieprawid³owa liczba indeksów.

    Matrix<double,3> ad3(n1,n2,n3);
    Matrix<double,3> ad33(n1,n2,n3);
    ad3 = ad33;                     // Dobrze: ten sam typ elementów, taka sama liczba wymiarów.
}

//------------------------------------------------------------------------------

void init(Matrix<int,2>& a) // Inicjacja ka¿dego elementu charakterystyczn¹ wartoœci¹.
{
    for (int i=0; i<a.dim1(); ++i)
        for (int j = 0; j<a.dim2(); ++j)
            a(i,j) = 10*i+j;
}

//------------------------------------------------------------------------------

void print(const Matrix<int,2>& a)  // Drukuje elementy wiersz po wierszu.
{
    for (int i=0; i<a.dim1(); ++i) {
        for (int j = 0; j<a.dim2(); ++j)
            cout << a(i,j) <<'\t';
        cout << '\n';
    }
}

//------------------------------------------------------------------------------

//void init(Matrix& a);  // B³¹d: brakuje typu elementów i liczby wymiarów.

//------------------------------------------------------------------------------

int main()
try
{
    Matrix<int,2> a(4,3);
    init(a);
    print(a);
    f1(10, 20, 30);
    f(10, 20, 30);
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
