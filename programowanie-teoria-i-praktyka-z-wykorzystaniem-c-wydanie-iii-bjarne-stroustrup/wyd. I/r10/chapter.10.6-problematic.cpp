
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

    if (ist.bad()) error("Strumieñ ist jest w stanie bad."); // Uszkodzony strumieñ — wynosimy siê st¹d!

    if (ist.fail()) {   // Uporz¹dkowanie, co siê da, i zg³oszenie problemu.
        ist.clear();    // Wyczyszczenie stanu strumienia,
                        // aby mo¿na by³o poszukaæ znaku koñcz¹cego.
        char c;
        ist>>c;         // Wczytanie znaku z nadziej¹, ¿e to znak koñcz¹cy.
        if (c != terminator) { // Niespodziewany znak.
            ist.unget();       // Oddanie z powrotem tego znaku.
            ist.clear(ios_base::failbit); // Ustawienie stanu na fail().
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
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
