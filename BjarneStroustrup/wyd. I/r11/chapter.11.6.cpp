
//
// To jest przyk³adowy kod z podrozdzia³u 11.6 „Klasyfikowanie znaków” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <cctype>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    char ch;
    while (cin.get(ch)) {
        if (isspace(ch)) {    // Jeœli ch jest bia³ym znakiem,
            // nic nie rób (tzn. pomiñ go).
        }
        if (isdigit(ch)) {
            // Wczytuje liczbê.
        }
        else if (isalpha(ch)) {
            // Wczytuje identyfikator.
        }
        else {
            // Obs³uga operatorów.
        }
    }
}

//------------------------------------------------------------------------------

void test(char c)
{
    isspace(c);    // Sprawdza, czy c jest bia³ym znakiem (' ', '\t', '\n' itp.).
    isalpha(c);    // Sprawdza, czy c jest liter¹ ('a', 'z', 'A', 'Z' itd., ale nie '_').
    isdigit(c);    // Sprawdza, czy c jest liczb¹ dziesiêtn¹ ('0'..'9').
    isxdigit(c);   // Sprawdza, czy c jest liczb¹ szesnastkow¹ (cyfra dziesiêtna lub litera 'a'..'f' lub 'A'..'F').
    isupper(c);    // Sprawdza, czy c jest wielk¹ liter¹.
    islower(c);    // Sprawdza, czy c jest ma³¹ liter¹.
    isalnum(c);    // Sprawdza, czy c jest liter¹ czy cyfr¹ dziesiêtn¹.
    iscntrl(c);    // Sprawdza, czy c jest znakiem steruj¹cym (kody ASCII 0..31 i 127).
    ispunct(c);    // Sprawdza, czy c nie jest liter¹, cyfr¹, bia³ym znakiem lub niewidocznym znakiem steruj¹cym.
    isprint(c);    // Sprawdza, czy c jest znakiem drukowalnym (ASCII ''..'~').
    isgraph(c);    // Sprawdza, czy c isalpha()|isdigit()|ispunct() (uwaga: nie spacja).

    toupper(c);    // c lub odpwoiednik c napisany wielkimi literami.
    tolower(c);    // c lub odpwoiednik c napisany ma³ymi literami.
}

//------------------------------------------------------------------------------

void tolower(string& s)    // Zamienia s na ma³e litery.
{
    for (int i=0; i<s.length(); ++i) s[i] = tolower(s[i]);
}

//------------------------------------------------------------------------------
