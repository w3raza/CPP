
//
// Przyk�adowy kod z rozdzia�u 4.6.3 "Przyk�ad z u�yciem tekstu" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Prosty s�ownik: lista posortowanych s��w.
int main()
{
    vector<string> words; 
    string temp;
    while (cin>>temp)                // Wczytywanie s��w oddzielanych bia�ymi znakami.
        words.push_back(temp);       // Wstawianie danych do wektora.

    cout << "Liczba s��w: " << words.size() << endl;

    sort(words.begin(),words.end()); // Sortowanie �od pocz�tku do ko�ca�.

    for (int i = 0; i< words.size(); ++i) 
        if (i==0 || words[i-1]!=words[i]) // Czy to jest nowe s�owo?
            cout << words[i] << "\n";
}

//------------------------------------------------------------------------------
