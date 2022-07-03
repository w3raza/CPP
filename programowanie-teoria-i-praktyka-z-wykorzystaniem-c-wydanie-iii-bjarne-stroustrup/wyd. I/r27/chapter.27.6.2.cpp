
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.6.2 „Wejœcie” ksi¹¿ki
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
    /* Wczytuje dane do zmiennych przekazywanych jako wskaŸniki: */
    scanf("%i %c %lg %s", &i, &c, &d, s);
    /* %s pomija znajduj¹cy siê na pocz¹tku bia³y znak i koñczy siê na bia³ym znaku. */
    printf("%i %c %lg %s", i, c, d, s);
}

//------------------------------------------------------------------------------

int main()
{
    f();

    // Najprostszy sposób na wczytanie ³añcucha znaków, to u¿ycie funkcji gets(). Na przyk³ad:

    char a[12];
    gets(a);     /* Wczytuje dane do tablicy znaków wskazywanej przez a a¿ do pojawienia siê znaku '\n'. */

    string s;
    cin >> s;    // wczytuje s³owo
    getline(cin,s);    // wczytuje wiersz

    char buf[20];
    scanf("%19s",buf);

    int x;
    while((x=getchar())!=EOF) {
        /* ... */ 
    }
}

//------------------------------------------------------------------------------
