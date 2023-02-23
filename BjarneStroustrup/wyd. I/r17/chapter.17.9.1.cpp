
//
// To jest przyk�adowy kod z podrozdzia�u 17.9.1 �Wska�niki i referencje jako parametry� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int  incr_v(int x) { return x+1; } // Oblicza now� warto�� i j� zwraca.
void incr_p(int* p) { ++*p; }      // przekazanie wska�nika
                                   // (wy�uskanie go i inkrementacja wyniku)
void incr_r(int& r) { ++r; }       // przekazanie referencji
void incr_p(char* p)
{
    if (p==0) error("Zerowy wska�nik podany jako argument funkcji incr_p().");
    ++*p; // Dereferencja wska�nika i inkrementacja wskazywanego przez niego obiektu.
}

//------------------------------------------------------------------------------

int main()
try
{
    {
        int x = 2;
        x = incr_v(x); // Kopiuje x do incr_v(); nast�pnie kopiuje wynik na zewn�trz i przypisuje go.
    }

    // U�ycie wska�nika jako argumentu jest znakiem dla programisty, �e co� mo�e si� zmieni�.
    {
        int x = 7;
        incr_p(&x);    // Operator & jest potrzebny.
        incr_r(x);
    }

    // Kto� m�g�by to wywo�a� przy u�yciu pustego wska�nika.
    {
        //incr_p(0);     // Awaria: funkcja incr_p() b�dzie pr�bowa� wy�uska� 0.
        char* p = 0;
        incr_p(p);     // Awaria: funkcja incr_p() b�dzie pr�bowa� wy�uska� 0.
    }
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
