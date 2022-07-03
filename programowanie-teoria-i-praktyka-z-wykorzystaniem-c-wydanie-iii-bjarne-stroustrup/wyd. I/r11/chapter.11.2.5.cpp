
//
// To jest przyk�adowy kod z podrozdzia�u 11.2.5 �Pola� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <iomanip>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << 123456                        // Bez pola.
         <<'|'<< setw(4) << 123456 << '|' // Liczba 123456 nie mie�ci si� w polu o szeroko�ci czterech znak�w.
         << setw(8) << 123456 << '|'      // Ustawia szeroko�� pola na osiem znak�w.
         << 123456 << "|\n";              // Szeroko�� pola nie jest �trwa�a�.

    cout << 12345 <<'|'<< setw(4) << 12345 << '|'
         << setw(8) << 12345 << '|' << 12345 << "|\n";
    cout << 1234.5 <<'|'<< setw(4) << 1234.5 << '|'
         << setw(8) << 1234.5 << '|' << 1234.5 << "|\n";
    cout << "asdfg" <<'|'<< setw(4) << "asdfg" << '|'
         << setw(8) << "asdfg" << '|' << "asdfg" << "|\n";
}

//------------------------------------------------------------------------------
