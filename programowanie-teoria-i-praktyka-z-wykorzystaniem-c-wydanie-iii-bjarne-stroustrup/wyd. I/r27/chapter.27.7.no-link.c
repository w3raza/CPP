/*
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.7 „Sta³e i makra” ksi¹¿ki
// „Programming -- Principles and Practice Using C++” Bjarne'a Stroustrupa
//
*/

/*----------------------------------------------------------------------------*/

const int max = 30;
const int x;    /* Nie zainicjowana sta³a. Dobrze w C (b³¹d w C++). */

/*----------------------------------------------------------------------------*/

void f(int v)
{
    /*int a1[max];*/  /* B³¹d: granica tablicy nie jest sta³¹ (dobrze w C++). */
                      /* (max nie mo¿e pojawiaæ siê w sta³ych wyra¿eniach!) */
    /*int a2[x];*/    /* B³¹d: granica tablicy nie jest sta³¹. */

    switch (v) {
    case 1:
        /* ... */
        break;
    /*case max:*/     /* B³¹d: etykieta case nie jest sta³¹ (dobrze w C++). */
        /* ... */
        break;
    }
}

/*----------------------------------------------------------------------------*/

/* Plik x.c: */
const int x;        /* inicjacja w innym miejscu */

/*----------------------------------------------------------------------------*/

/* Plik xx.c: */
const int x = 7;    /* Tutaj znajduje siê prawdziwa definicja. */

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
