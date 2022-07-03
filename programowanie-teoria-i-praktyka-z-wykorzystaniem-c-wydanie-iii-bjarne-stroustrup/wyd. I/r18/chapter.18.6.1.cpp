
//
// To jest przyk�adowy kod z podrozdzia�u 18.6.1 �Wykorzystanie �a�cuch�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const string& s)
{
    int first = 0;            // Indeks pierwszej litery.
    int last = s.length()-1;  // Indeks ostatniej litery.
    while (first < last) {    // Nie doszli�my jeszcze do �rodka.
        if (s[first]!=s[last]) return false;
        ++first;              // Przesuwa w prz�d.
        --last;               // Przesuwa wstecz.
    }
    return true;
}

//------------------------------------------------------------------------------

int main()
{
    string s;
    while (cin>>s) {
        cout << s;
        if (!is_palindrome(s)) cout << " nie";
        cout << " jest palindromem.\n";
    }
}

//------------------------------------------------------------------------------
