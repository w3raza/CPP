
//
// Przyk³adowy kod z rozdzia³u 5.6.2 "B³êdy zakresu" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void foo()
{
    vector<int> v;                     // Wektor liczb typu int.
    int i;
    while (cin>>i) v.push_back(i);     // pobieranie wartoœci
    for (int i = 0; i<=v.size(); ++i)  // drukowanie wartoœci
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
    while (cin>>x) v.push_back(x);     // ustawianie wartoœci
    for (int i = 0; i<=v.size(); ++i)  // drukowanie wartoœci
        cout << "v[" << i <<"] == " << v[i] << endl;
} catch (out_of_range) {
    cerr << "B³¹d zakresu.\n";
    return 1;
} catch (...) {                        // Przechwytuje wszystkie pozosta³e wyj¹tki.
    cerr << "Wyj¹tek: coœ zawiod³o.\n";
    return 2;
}

//------------------------------------------------------------------------------
