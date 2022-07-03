
//
// To jest przyk�adowy kod z rozdzia�u 3.6.1 "Przyk�ad zliczania powtarzaj�cych si� s��w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int number_of_words = 0;
    string previous = " ";      // nie s�owo
    string current;
    while (cin>>current) {
        ++number_of_words;      // zwi�ksza licznik s��w
        if (previous == current)
            cout << "S�owo numer " << number_of_words
                 << " powtarza si�: "<< current << '\n';
        previous = current;
    }
}

//------------------------------------------------------------------------------
