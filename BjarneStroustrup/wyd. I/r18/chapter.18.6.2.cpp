
//
// To jest przyk�adowy kod z podrozdzia�u 18.6.2 �Wykorzystanie tablic� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const char s[], int n)
// s wskazuje pierwszy znak tablicy n znak�w.
{
    int first = 0;         // Indeks pierwszej litery.
    int last = n-1;        // Indeks ostatniej litery.
    while (first < last) { // Nie doszli�my jeszcze do �rodka.
        if (s[first]!=s[last]) return false;
        ++first;           // Przesuwa w prz�d.
        --last;            // Przesuwa wstecz.
    }
    return true;
}

//------------------------------------------------------------------------------

istream& read_word(istream& is, char* buffer, int max)
// Wczytuje najwy�ej max�1 znak�w z is do bufora.
{
    is.width(max);         // Wczytuje najwy�ej max�1 znak�w w znajduj�cym si� dalej >>.
    is >> buffer;          // Wczytuje zako�czone spacj� s�owo,
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
