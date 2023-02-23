
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.4 �Pami�� wolna� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//------------------------------------------------------------------------------

struct Pair {
    const char* p;
    int val;
};

//------------------------------------------------------------------------------

struct X { int x; };

//------------------------------------------------------------------------------

void quit() { exit(0); }

//------------------------------------------------------------------------------

int main()
{
    struct Pair p2 = {"jab�ko",78};
    struct Pair* pp = (struct Pair*) malloc(sizeof(Pair));    /* alokacja */
    pp->p = "pear";    /* inicjacja */
    pp->val = 42;

    // Nie mo�na napisa�
    // *pp = {"gruszka", 42};
    // ani w C, ani w C++. Jednak w j�zyku C++ zdefiniowaliby�my konstruktor dla Pair i napisaliby�my
    // Pair* pp = new Pair("pear", 42);

    int  n = 10;
    int  m = 20;

#ifndef __cplusplus
    int* p = malloc(sizeof(int)*n); /* unikaj tego */

    p = malloc(sizeof(char)*m);     /* Pewnie b��d � nie alokuje miejsca dla m liczb typu int. */
#endif

    {
        int* p = new int[200];
        // ...
        free(p);    // B��d

        X* q = (X*)malloc(n*sizeof(X));
        // ...
        delete q;   // B��d
    }

    int max = 1000; 
    int count = 0;
    int c;
    char* p = (char*)malloc(max);
    while ((c=getchar())!=EOF) {  /* Czytaj: ignoruj znaki w wierszu ko�ca pliku. */
        if (count==max-1) {       /* Trzeba rozszerzy� bufor. */
            max += max;           /* Podwaja rozmiar bufora. */
            p = (char*)realloc(p,max);
            if (p==0) quit();
        }
        p[count++] = c;
    }

    // Odpowiednik tego kodu napisany przy u�yciu biblioteki standardowej:
    {
        vector<char> buf;
        char c;
        while (cin.get(c)) buf.push_back(c);
    }
}

//------------------------------------------------------------------------------
