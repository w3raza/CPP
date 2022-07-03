
//
// To jest przyk³adowy kod z rozdzia³u 3.6.1 "Przyk³ad zliczania powtarzaj¹cych siê s³ów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int number_of_words = 0;
    string previous = " ";      // nie s³owo
    string current;
    while (cin>>current) {
        ++number_of_words;      // zwiêksza licznik s³ów
        if (previous == current)
            cout << "S³owo numer " << number_of_words
                 << " powtarza siê: "<< current << '\n';
        previous = current;
    }
}

//------------------------------------------------------------------------------
