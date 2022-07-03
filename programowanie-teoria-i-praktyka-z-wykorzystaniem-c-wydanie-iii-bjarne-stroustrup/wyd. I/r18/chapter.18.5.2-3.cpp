
//
// To jest przyk�adowy kod z podrozdzia�u 18.5.2 "Wska�niki i tablice" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Nazwa tablicy odnosi si� do wszystkich jej element�w.
char ch[100];
char* p = ch; // Zmienna p jest inicjowana warto�ci� &ch[0].

//------------------------------------------------------------------------------

int main()
{
    //ch = new char [20];        // B��d: nie mo�na przypisywa� do nazwy tablicy.
    //&ch[0] = new char [20];    // B��d: nie mo�na przypisywa� do warto�ci wska�nika.

    int x[100];
    int y[100];
    // ...
    //x = y;          // b��d
    //int z[100] = y; // b��d

    for (int i=0; i<100; ++i) x[i]=y[i]; // Kopiuje 100 liczb typu int.
    memcpy(x,y,100*sizeof(int));         // Kopiuje 100*sizeof(int) bajt�w.
    copy(y,y+100, x);                    // Kopiuje 100 liczb typu int.

    // Aby m�c przypisywa�, nale�y u�y� jakiej� struktury w rodzaju wektora.
    {
        vector<int> x(100);
        vector<int> y(100);
        // ...
        x = y;                           // Kopiuje 100 liczb typu int.
    }
}

//------------------------------------------------------------------------------
