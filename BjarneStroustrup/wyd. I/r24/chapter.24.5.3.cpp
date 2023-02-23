
//
// To jest przyk�adowy kod z podrozdzia�u 24.5.3 �Macierze dwuwymiarowe� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "Matrix.h"

using namespace Numeric_lib;

//------------------------------------------------------------------------------

int f(int a) { return a*a; }

//------------------------------------------------------------------------------

int g(int a, int b) { return a*b; }

//------------------------------------------------------------------------------

enum Piece { none, pawn, knight, queen, king, bishop, rook};

//------------------------------------------------------------------------------

void board()
{
    //enum Piece { none, pawn, knight, queen, king, bishop, rook };
    Matrix<Piece,2> board(8,8);        // szachownica

    const int white_start_row = 0;
    const int black_start_row = 7;

    //Matrix<Piece>& white_start = board[0]; // Dzia�a w MS C++, ale nie dzia�a w ISO C++; wi��e si� z r-warto�ci�
    //Matrix<Piece>& red_start = board[7];

    Piece a[] = { rook, knight, bishop, queen, king, bishop, knight, rook};
    Matrix<Piece> start_row(a); // = { castle, knight, bishop, queen, king, bishop, knight, castle};
    Matrix<Piece> clear_row(8);

    board[white_start_row] = start_row;    // resetuje bia�e figury
    for (int i = 1; i<7; ++i) board[i] = clear_row;    // czy�ci �rodek planszy
    board[black_start_row] = start_row;    // resetuje czarne figury
}

//------------------------------------------------------------------------------

int main()
{
    Matrix<int,2> a(3,4);

    int s  = a.size();    // liczba element�w
    int d1 = a.dim1();     // liczba element�w w wierszu
    int d2 = a.dim2();    // liczba element�w w kolumnie
    int* p = a.data();    // Wyodr�bnia dane jako wska�nik do tablicy w stylu j�zyka C.

    int  i = 1;
    int  j = 2;
    int  n = 2;
    a(i,j);               // (i,j)-ty element (styl j�zyka Fortran), ale ze sprawdzaniem zakresu
    a[i];                 // i-ty wiersz (styl j�zyka C), ze sprawdzaniem zakresu
    a[i][j];              // (i,j)-ty element (styl j�zyka C)

    a.slice(i);           // wiersze od elementu a[i] do ostatniego
    a.slice(i,n);         // wiersze od elementu a[i] do a[i+n�1].

    Matrix<int,2> a2 = a; // inicjowanie kopiuj�ce
    a = a2;               // przypisanie kopiuj�ce
    a *= 7;               // skalowanie (tak�e +=, �=, /=, itp.)
    a.apply(f);           // a(i,j)=f(a(i,j)) dla ka�dego elementu a(i,j)
    a.apply(g,7);         // a(i,j)=f(a(i,j),7) dla ka�dego elementu a(i,j)
    Matrix<int,2> b(3,4);
    b=apply(f,a);         // Tworzy now� macierz, w kt�rej b(i,j)==f(a(i,j))
    b=apply(g,a,7);       // Tworzy now� macierz, w kt�rej b(i,j)==f(a(i,j),7)

    a.swap_rows(1,2);     // Zamienia wiersze � a[1] <�> a[2].

    board();
}

//------------------------------------------------------------------------------
