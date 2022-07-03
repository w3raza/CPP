
//
// Przyk�adowy kod z rozdzia�u 5.6.2 "B��dy zakresu" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void foo()
{
    vector<int> v;                     // Wektor liczb typu int.
    int i;
    while (cin>>i) v.push_back(i);     // pobieranie warto�ci
    for (int i = 0; i<=v.size(); ++i)  // drukowanie warto�ci
        cout << "v[" << i <<"] == " << v[i] << endl;
}

//------------------------------------------------------------------------------

void bar()
{
    vector<int> v(5);
    int x = v[5];
}

//------------------------------------------------------------------------------

int main()
try {
    vector<int> v;                     // Wektor liczb typu int.
    int x;
    while (cin>>x) v.push_back(x);     // ustawianie warto�ci
    for (int i = 0; i<=v.size(); ++i)  // drukowanie warto�ci
        cout << "v[" << i <<"] == " << v[i] << endl;
} catch (out_of_range) {
    cerr << "B��d zakresu.\n";
    return 1;
} catch (...) {                        // Przechwytuje wszystkie pozosta�e wyj�tki.
    cerr << "Wyj�tek: co� zawiod�o.\n";
    return 2;
}

//------------------------------------------------------------------------------
