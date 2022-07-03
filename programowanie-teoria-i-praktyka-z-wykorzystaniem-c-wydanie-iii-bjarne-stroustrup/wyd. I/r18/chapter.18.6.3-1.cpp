
//
// To jest przyk�adowy kod z podrozdzia�u 18.6.3 �Wykorzystanie wska�nik�w� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const char* first, const char* last)
// Wska�nik first wskazuje pierwsz� liter�, last � ostatni�.
{
    while (first < last) {        // Nie doszli�my jeszcze do �rodka.
        if (*first!=*last) return false;
        ++first;    // przesuwa w prz�d
        --last;        // przesuwa wstecz
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
