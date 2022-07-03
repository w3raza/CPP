
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.6.2 �Wej�cie� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

void f()
{
    int i;
    char c;
    double d;
    char* s = (char*)malloc(100);
    /* Wczytuje dane do zmiennych przekazywanych jako wska�niki: */
    scanf("%i %c %lg %s", &i, &c, &d, s);
    /* %s pomija znajduj�cy si� na pocz�tku bia�y znak i ko�czy si� na bia�ym znaku. */
    printf("%i %c %lg %s", i, c, d, s);
}

//------------------------------------------------------------------------------

int main()
{
    f();

    // Najprostszy spos�b na wczytanie �a�cucha znak�w, to u�ycie funkcji gets(). Na przyk�ad:

    char a[12];
    gets(a);     /* Wczytuje dane do tablicy znak�w wskazywanej przez a a� do pojawienia si� znaku '\n'. */

    string s;
    cin >> s;    // wczytuje s�owo
    getline(cin,s);    // wczytuje wiersz

    char buf[20];
    scanf("%19s",buf);

    int x;
    while((x=getchar())!=EOF) {
        /* ... */ 
    }
}

//------------------------------------------------------------------------------
