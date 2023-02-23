
//
// To jest przyk³adowy kod z podrozdzia³u 24.5.5 „Macierze trójwymiarowe” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "MatrixIO.h"

using namespace Numeric_lib;

//------------------------------------------------------------------------------

int f(int a) { return a*a; }

//------------------------------------------------------------------------------

int g(int a, int b) { return a*b; }

//------------------------------------------------------------------------------

int main()
{
	Matrix<int,3> a(10,20,30);

	a.size();             // liczba elementów
	a.dim1();             // liczba elementów w wymiarze 1
	a.dim2();             // liczba elementów w wymiarze 2
	a.dim3();             // liczba elementów w wymiarze 3
	int* p = a.data();    // wydobywa dane jako wskaŸnik do tablicy w stylu jêzyka C
	a(i,j,k);             // (i,j,k)-ty element (styl jêzyka Fortran), ale ze sprawdzaniem zakresu
	a[i];                 // i-ty wiersz (styl jêzyka C), ze sprawdzaniem zakresu
	a[i][j][k];           // (i,j,k)-ty element (styl jêzyka C)
	a.slice(i);           // elementy od i-tego do ostatniego
	a.slice(i,j);         // elementy od i-tego do j-tego
	Matrix<int,3> a2 = a; // inicjowanie kopiuj¹ce
	a = a2;               // przypisanie kopiuj¹ce
	a *= 7;               // skalowanie (oraz +=, –=, /= itd.)
	a.apply(f);           // a(i,j,k)=f(a(i,j,k)) dla ka¿dego elementu a(i,j,k)
	a.apply(f,7);         // a(i,j,k)=f(a(i,j,k),7) dla ka¿dego elementu a(i,j,k)
	b=apply(f,a);         // tworzy now¹ macierz, w której b(i,j,k)==f(a(i,j,k))
	b=apply(f,a,7);       // tworzy now¹ macierz, w której b(i,j,k)==f(a(i,j,k),7)
	a.swap_rows(7,9);     // zamienia wiersze a[7] <–> a[9]


	int grid_nx = 5;   // rozdzielczoœæ siatki; ustawiana na pocz¹tku
	int grid_ny = 5;
	int grid_nz = 5;
	Matrix<double,3> cube(grid_nx, grid_ny, grid_nz);
}

//------------------------------------------------------------------------------
