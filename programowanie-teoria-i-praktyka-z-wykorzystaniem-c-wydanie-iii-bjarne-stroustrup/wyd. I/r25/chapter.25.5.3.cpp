
//
// To jest przyk³adowy kod z podrozdzia³u 25.5.3 „Liczby ze znakiem i bez znaku” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

void infinite()
{
    unsigned char max = 160;    // bardzo du¿a
    for (signed char i=0; i<max; ++i) cout << int(i) << endl;
}

//------------------------------------------------------------------------------

template<class T> void print(T i) { cout << i << '\t'; }

//------------------------------------------------------------------------------

void print(char i) { cout << int(i) << '\t'; }

//------------------------------------------------------------------------------

void print(signed char i) { cout << int(i) << '\t'; }

//------------------------------------------------------------------------------

void print(unsigned char i) { cout << int(i) << '\t'; }

//------------------------------------------------------------------------------

int main()
{
    vector<int> v;
    // ...
    for (int i = 0; i<v.size(); ++i) cout << i << endl;
    
    for (vector<int>::size_type i = 0; i<v.size(); ++i) cout << i << endl;
    
    for (vector<int>::iterator p = v.begin(); p!=v.end(); ++p) cout << p-v.begin() << endl;

    // ...
    {
        unsigned int ui = -1;
        int si = ui;
        int si2 = ui+2;
        unsigned ui2 = ui+2;
    }

    // Jakie s¹ skutki przepe³nienia typu ca³kowitoliczbowego?

    short int i = 0;
    while (++i) print(i); // Drukuje i jako liczbê ca³kowit¹ i spacjê.

    int si = 257;         // Nie mieœci siê w typie char.
    char c = si;          // Niejawna konwersja na typ char.
    unsigned char uc = si;
    signed char sc = si;
    print(si); print(c); print(uc); print(sc); cout << endl;

    si = 129;             // Nie mieœci siê w typie signed char.
    c = si;
    uc = si;
    sc = si;
    print(si); print(c); print(uc); print(sc);
}

//------------------------------------------------------------------------------
