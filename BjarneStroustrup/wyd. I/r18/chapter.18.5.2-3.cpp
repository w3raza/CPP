
//
// To jest przyk³adowy kod z podrozdzia³u 18.5.2 "WskaŸniki i tablice" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Nazwa tablicy odnosi siê do wszystkich jej elementów.
char ch[100];
char* p = ch; // Zmienna p jest inicjowana wartoœci¹ &ch[0].

//------------------------------------------------------------------------------

int main()
{
    //ch = new char [20];        // B³¹d: nie mo¿na przypisywaæ do nazwy tablicy.
    //&ch[0] = new char [20];    // B³¹d: nie mo¿na przypisywaæ do wartoœci wskaŸnika.

    int x[100];
    int y[100];
    // ...
    //x = y;          // b³¹d
    //int z[100] = y; // b³¹d

    for (int i=0; i<100; ++i) x[i]=y[i]; // Kopiuje 100 liczb typu int.
    memcpy(x,y,100*sizeof(int));         // Kopiuje 100*sizeof(int) bajtów.
    copy(y,y+100, x);                    // Kopiuje 100 liczb typu int.

    // Aby móc przypisywaæ, nale¿y u¿yæ jakiejœ struktury w rodzaju wektora.
    {
        vector<int> x(100);
        vector<int> y(100);
        // ...
        x = y;                           // Kopiuje 100 liczb typu int.
    }
}

//------------------------------------------------------------------------------
