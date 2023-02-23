
//
// To jest przyk³adowy kod z podrozdzia³u 18.6.1 „Wykorzystanie ³añcuchów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const string& s)
{
    int first = 0;            // Indeks pierwszej litery.
    int last = s.length()-1;  // Indeks ostatniej litery.
    while (first < last) {    // Nie doszliœmy jeszcze do œrodka.
        if (s[first]!=s[last]) return false;
        ++first;              // Przesuwa w przód.
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
