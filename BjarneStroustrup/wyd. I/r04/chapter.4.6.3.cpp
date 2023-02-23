
//
// Przyk³adowy kod z rozdzia³u 4.6.3 "Przyk³ad z u¿yciem tekstu" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Prosty s³ownik: lista posortowanych s³ów.
int main()
{
    vector<string> words; 
    string temp;
    while (cin>>temp)                // Wczytywanie s³ów oddzielanych bia³ymi znakami.
        words.push_back(temp);       // Wstawianie danych do wektora.

    cout << "Liczba s³ów: " << words.size() << endl;

    sort(words.begin(),words.end()); // Sortowanie „od pocz¹tku do koñca”.

    for (int i = 0; i< words.size(); ++i) 
        if (i==0 || words[i-1]!=words[i]) // Czy to jest nowe s³owo?
            cout << words[i] << "\n";
}

//------------------------------------------------------------------------------
