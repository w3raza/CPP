
//
// To jest przyk³adowy kod z podrozdzia³u 10.6 „Obs³uga b³êdów wejœcia i wyjœcia” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void fill_vector(istream& ist, vector<int>& v, char terminator)
// Wczytuje liczby ca³kowite ze strumienia ist do wektora v do chwili napotkania eof() lub znaku oznaczaj¹cego koniec danych.
{
    int i = 0;
    while (ist >> i) v.push_back(i);
    if (ist.eof()) return;    // Dobrze: znaleziono koniec pliku.

    // Nie good(), nie bad() i nie eof(), a wiêc ist musi byæ w stanie fail().
    ist.clear();              // Czyœci stan strumienia.
    char c;
    ist>>c;                   // Wczytanie znaku z nadziej¹, ¿e to znak koñcz¹cy.

    if (c != terminator) {    // Nie znak koñcz¹cy, bêdzie niepowodzenie.
        ist.unget();          // Mo¿e wywo³uj¹cy bêdzie wiedzia³, co zrobiæ z tym znakiem.
        ist.clear(ios_base::failbit); // Ustawia stan na fail().
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    cin.exceptions(cin.exceptions()|ios_base::badbit);

    vector<int> v;
    fill_vector(cin, v, '*');
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
