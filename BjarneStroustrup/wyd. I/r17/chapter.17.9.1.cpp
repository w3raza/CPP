
//
// To jest przyk³adowy kod z podrozdzia³u 17.9.1 „WskaŸniki i referencje jako parametry” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int  incr_v(int x) { return x+1; } // Oblicza now¹ wartoœæ i j¹ zwraca.
void incr_p(int* p) { ++*p; }      // przekazanie wskaŸnika
                                   // (wy³uskanie go i inkrementacja wyniku)
void incr_r(int& r) { ++r; }       // przekazanie referencji
void incr_p(char* p)
{
    if (p==0) error("Zerowy wskaŸnik podany jako argument funkcji incr_p().");
    ++*p; // Dereferencja wskaŸnika i inkrementacja wskazywanego przez niego obiektu.
}

//------------------------------------------------------------------------------

int main()
try
{
    {
        int x = 2;
        x = incr_v(x); // Kopiuje x do incr_v(); nastêpnie kopiuje wynik na zewn¹trz i przypisuje go.
    }

    // U¿ycie wskaŸnika jako argumentu jest znakiem dla programisty, ¿e coœ mo¿e siê zmieniæ.
    {
        int x = 7;
        incr_p(&x);    // Operator & jest potrzebny.
        incr_r(x);
    }

    // Ktoœ móg³by to wywo³aæ przy u¿yciu pustego wskaŸnika.
    {
        //incr_p(0);     // Awaria: funkcja incr_p() bêdzie próbowaæ wy³uskaæ 0.
        char* p = 0;
        incr_p(p);     // Awaria: funkcja incr_p() bêdzie próbowaæ wy³uskaæ 0.
    }
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
