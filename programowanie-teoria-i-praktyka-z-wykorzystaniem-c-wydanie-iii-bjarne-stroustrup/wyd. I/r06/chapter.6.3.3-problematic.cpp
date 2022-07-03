
//
// Przyk³adowy kod z rozdzia³u 6.3.3 "Implementowanie tokenów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {        // Bardzo prosty typ zdefiniowany przez u¿ytkownika.
public:
    char kind;
    double value;
};

//------------------------------------------------------------------------------

int main()
try
{
    Token t;         // Zmienna t jest typu Token.
    t.kind = '+';    // Zmienna t reprezentuje znak +.
    Token t2;        // Zmienna t2 jest innym obiektem typu Token.
    t2.kind = '8';   // Cyfra 8 oznacza rodzaj (kind) tokenu bêd¹cy liczb¹.
    t2.value = 3.14;

    Token tt = t;    // Inicjacja kopii
    if (tt.kind != t.kind) error("To niemo¿liwe!");
    t = t2;          // przypisanie
    cout << t.value; // wydrukuje 3.14
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
