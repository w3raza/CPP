
//
// To jest przyk�adowy kod z podrozdzia�u 18.6.3 �Wykorzystanie wska�nik�w� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const char* first, const char* last)
// Wska�nik first wskazuje pierwsz� liter�, last � ostatni�.
{
    if (first<last) {
        if (*first!=*last) return false;
        return is_palindrome(++first,--last);
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
        cout << s << " is";
        if (!is_palindrome(s,strlen(s))) cout << " nie";
        cout << " jest palindromem.\n";
    }
}

//------------------------------------------------------------------------------
