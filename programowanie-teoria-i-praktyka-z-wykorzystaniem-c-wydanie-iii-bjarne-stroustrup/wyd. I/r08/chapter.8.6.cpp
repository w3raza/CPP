
//
// To jest przyk³adowy kod z podrozdzia³u 8.6 „Porz¹dek wykonywania instrukcji” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

string program_name = "g³upi";
vector<string> v;                // v jest zmienn¹ globaln¹.

void f()
{
    string s;                    // Zmienna s jest lokalna w funkcji f.
    while (cin>>s && s!="koniec") {
        string stripped;         // Zmienna stripped jest lokalna w pêtli.
        string not_letters;
        for (int i=0; i<s.size(); ++i)    // i ma zakres instrukcji.
            if (isalpha(s[i]))
                stripped += s[i];
            else
                not_letters += s[i];
        v.push_back(stripped);
        // ...
    }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
