
//
// To jest przyk³adowy kod z podrozdzia³u 18.6.3 „Wykorzystanie wskaŸników” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

bool is_palindrome(const char* first, const char* last)
// WskaŸnik first wskazuje pierwsz¹ literê, last — ostatni¹.
{
    while (first < last) {        // Nie doszliœmy jeszcze do œrodka.
        if (*first!=*last) return false;
        ++first;    // przesuwa w przód
        --last;        // przesuwa wstecz
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
