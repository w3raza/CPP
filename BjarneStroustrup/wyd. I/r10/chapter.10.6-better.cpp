
//
// To jest przyk�adowy kod z podrozdzia�u 10.6 �Obs�uga b��d�w wej�cia i wyj�cia� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void fill_vector(istream& ist, vector<int>& v, char terminator)
// Wczytuje liczby ca�kowite ze strumienia ist do wektora v do chwili napotkania eof() lub znaku oznaczaj�cego koniec danych.
{
    int i = 0;
    while (ist >> i) v.push_back(i);
    if (ist.eof()) return;    // Dobrze: znaleziono koniec pliku.

    // Nie good(), nie bad() i nie eof(), a wi�c ist musi by� w stanie fail().
    ist.clear();              // Czy�ci stan strumienia.
    char c;
    ist>>c;                   // Wczytanie znaku z nadziej�, �e to znak ko�cz�cy.

    if (c != terminator) {    // Nie znak ko�cz�cy, b�dzie niepowodzenie.
        ist.unget();          // Mo�e wywo�uj�cy b�dzie wiedzia�, co zrobi� z tym znakiem.
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
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
