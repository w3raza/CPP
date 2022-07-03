
//
// To jest przyk�adowy kod z podrozdzia�u 24.4 �Tablice wielowymiarowe w stylu j�zyka C� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    int ai[4];        // tablica jednowymiarowa
    double ad[3][4];  // tablica dwuwymiarowa
    char ac[3][4][5]; // tablica tr�jwymiarowa
    ai[1] = 7;
    ad[2][3] = 7.2;
    ac[2][3][4] = 'c';    
}

//------------------------------------------------------------------------------

void f1(int a[3][5]);                     // Przydatne tylko dla macierzy [3][5].

//------------------------------------------------------------------------------

void f2(int [ ][5], int dim1);            // Pierwszy wymiar mo�e by� zmienny.

//------------------------------------------------------------------------------

//void f3(int [5 ][ ], int dim2);         // B��d: drugi wymiar nie mo�e by� zmienny.

//------------------------------------------------------------------------------

//void f4(int[ ][ ], int dim1, int dim2); // B��d (i tak by nie zadzia�a�o).

//------------------------------------------------------------------------------

void f5(int* m, int dim1, int dim2)       // Dziwne, ale dzia�a.
{
    for (int i=0; i<dim1; ++i)
        for (int j = 0; j<dim2; ++j) m[i*dim2+j] = 0;
}

//------------------------------------------------------------------------------
