
//
// To jest przyk�adowy kod z podrozdzia�u 11.6 �Klasyfikowanie znak�w� ksi��ki 
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
        if (isspace(ch)) {    // Je�li ch jest bia�ym znakiem,
            // nic nie r�b (tzn. pomi� go).
        }
        if (isdigit(ch)) {
            // Wczytuje liczb�.
        }
        else if (isalpha(ch)) {
            // Wczytuje identyfikator.
        }
        else {
            // Obs�uga operator�w.
        }
    }
}

//------------------------------------------------------------------------------

void test(char c)
{
    isspace(c);    // Sprawdza, czy c jest bia�ym znakiem (' ', '\t', '\n' itp.).
    isalpha(c);    // Sprawdza, czy c jest liter� ('a', 'z', 'A', 'Z' itd., ale nie '_').
    isdigit(c);    // Sprawdza, czy c jest liczb� dziesi�tn� ('0'..'9').
    isxdigit(c);   // Sprawdza, czy c jest liczb� szesnastkow� (cyfra dziesi�tna lub litera 'a'..'f' lub 'A'..'F').
    isupper(c);    // Sprawdza, czy c jest wielk� liter�.
    islower(c);    // Sprawdza, czy c jest ma�� liter�.
    isalnum(c);    // Sprawdza, czy c jest liter� czy cyfr� dziesi�tn�.
    iscntrl(c);    // Sprawdza, czy c jest znakiem steruj�cym (kody ASCII 0..31 i 127).
    ispunct(c);    // Sprawdza, czy c nie jest liter�, cyfr�, bia�ym znakiem lub niewidocznym znakiem steruj�cym.
    isprint(c);    // Sprawdza, czy c jest znakiem drukowalnym (ASCII ''..'~').
    isgraph(c);    // Sprawdza, czy c isalpha()|isdigit()|ispunct() (uwaga: nie spacja).

    toupper(c);    // c lub odpwoiednik c napisany wielkimi literami.
    tolower(c);    // c lub odpwoiednik c napisany ma�ymi literami.
}

//------------------------------------------------------------------------------

void tolower(string& s)    // Zamienia s na ma�e litery.
{
    for (int i=0; i<s.length(); ++i) s[i] = tolower(s[i]);
}

//------------------------------------------------------------------------------
