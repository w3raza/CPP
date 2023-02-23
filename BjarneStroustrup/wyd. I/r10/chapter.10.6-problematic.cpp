
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

    if (ist.bad()) error("Strumie� ist jest w stanie bad."); // Uszkodzony strumie� � wynosimy si� st�d!

    if (ist.fail()) {   // Uporz�dkowanie, co si� da, i zg�oszenie problemu.
        ist.clear();    // Wyczyszczenie stanu strumienia,
                        // aby mo�na by�o poszuka� znaku ko�cz�cego.
        char c;
        ist>>c;         // Wczytanie znaku z nadziej�, �e to znak ko�cz�cy.
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
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
