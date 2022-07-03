
//
// To jest przyk³adowy kod z podrozdzia³u 11.2.5 „Pola” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <iomanip>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    cout << 123456                        // Bez pola.
         <<'|'<< setw(4) << 123456 << '|' // Liczba 123456 nie mieœci siê w polu o szerokoœci czterech znaków.
         << setw(8) << 123456 << '|'      // Ustawia szerokoœæ pola na osiem znaków.
         << 123456 << "|\n";              // Szerokoœæ pola nie jest „trwa³a”.

    cout << 12345 <<'|'<< setw(4) << 12345 << '|'
         << setw(8) << 12345 << '|' << 12345 << "|\n";
    cout << 1234.5 <<'|'<< setw(4) << 1234.5 << '|'
         << setw(8) << 1234.5 << '|' << 1234.5 << "|\n";
    cout << "asdfg" <<'|'<< setw(4) << "asdfg" << '|'
         << setw(8) << "asdfg" << '|' << "asdfg" << "|\n";
}

//------------------------------------------------------------------------------
