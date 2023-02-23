
//
// To jest przyk³adowy kod z podrozdzia³u 18.6.2 „Wykorzystanie tablic” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const char s[], int n)
// s wskazuje pierwszy znak tablicy n znaków.
{
    int first = 0;         // Indeks pierwszej litery.
    int last = n-1;        // Indeks ostatniej litery.
    while (first < last) { // Nie doszliœmy jeszcze do œrodka.
        if (s[first]!=s[last]) return false;
        ++first;           // Przesuwa w przód.
        --last;            // Przesuwa wstecz.
    }
    return true;
}

//------------------------------------------------------------------------------

istream& read_word(istream& is, char* buffer, int max)
// Wczytuje najwy¿ej max–1 znaków z is do bufora.
{
    is.width(max);         // Wczytuje najwy¿ej max–1 znaków w znajduj¹cym siê dalej >>.
    is >> buffer;          // Wczytuje zakoñczone spacj¹ s³owo,
                           // i dodaje zero za ostatnim znakiem wczytanym do p.
    return is;
}

//------------------------------------------------------------------------------

int main()
{
    const int max = 128;
    char s[max];
    while (read_word(cin,s,max)) { 
        cout << s;
        if (!is_palindrome(s,strlen(s))) cout << " nie";
        cout << " jest palindromem.\n";
    }
}

//------------------------------------------------------------------------------
