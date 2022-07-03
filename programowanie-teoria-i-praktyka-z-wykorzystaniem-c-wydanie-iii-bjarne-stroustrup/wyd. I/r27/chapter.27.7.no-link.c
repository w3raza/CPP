/*
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.7 �Sta�e i makra� ksi��ki
// �Programming -- Principles and Practice Using C++� Bjarne'a Stroustrupa
//
*/

/*----------------------------------------------------------------------------*/

const int max = 30;
const int x;    /* Nie zainicjowana sta�a. Dobrze w C (b��d w C++). */

/*----------------------------------------------------------------------------*/

void f(int v)
{
    /*int a1[max];*/  /* B��d: granica tablicy nie jest sta�� (dobrze w C++). */
                      /* (max nie mo�e pojawia� si� w sta�ych wyra�eniach!) */
    /*int a2[x];*/    /* B��d: granica tablicy nie jest sta��. */

    switch (v) {
    case 1:
        /* ... */
        break;
    /*case max:*/     /* B��d: etykieta case nie jest sta�� (dobrze w C++). */
        /* ... */
        break;
    }
}

/*----------------------------------------------------------------------------*/

/* Plik x.c: */
const int x;        /* inicjacja w innym miejscu */

/*----------------------------------------------------------------------------*/

/* Plik xx.c: */
const int x = 7;    /* Tutaj znajduje si� prawdziwa definicja. */

#define  MAX 30

void f1(int v)
{
    int a1[MAX];        /* ok */

    switch (v) {
    case 1:
        /* ... */
        break;
    case MAX:        /* ok */
        /* ... */
        break;
    }
}

/*----------------------------------------------------------------------------*/
