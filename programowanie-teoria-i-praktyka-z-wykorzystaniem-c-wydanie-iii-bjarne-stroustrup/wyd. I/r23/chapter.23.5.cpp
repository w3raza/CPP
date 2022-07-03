
//
// To jest przyk³adowy kod z podrozdzia³u 23.5 „Problem” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <string>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
    string s;
    while (cin>>s) {
        if (s.size()==7
            && isalpha(s[0]) && isalpha(s[1])
            && isdigit(s[2]) && isdigit(s[3]) && isdigit(s[4])
            && isdigit(s[5]) && isdigit(s[6]))
            cout << "znaleziono " << s << '\n';
    }
}

//------------------------------------------------------------------------------
