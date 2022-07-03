
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.4 �Przekazywanie argument�w przez sta�� referencj� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print(const vector<double>& v)    // Przekazywanie przez sta�� referencj�.
{
    cout << "{ ";
    for (int i = 0; i<v.size(); ++i) {
        cout << v[i];
        if (i!=v.size()-1) cout << ", ";
    }
    cout << " }\n";
}

//------------------------------------------------------------------------------

void f(int x)
{
    vector<double> vd1(10);            // Ma�y wektor
    vector<double> vd2(10000);         // Du�y wektor
    vector<double> vd3(x);             // Wrektor o nieznanym rozmiarze
    // ... wype�nianie vd1, vd2, vd3 warto�ciami ...
    print(vd1);
    print(vd2);
    print(vd3);
}

//------------------------------------------------------------------------------

int my_find(vector<string> vs, string s); // Przekazanie przez warto�� � kopiowanie.

// Przekazywanie przez sta�� referencj� � bez kopiowania, dost�p polegaj�cy tylko na odczycie.
int my_find(const vector<string>& vs, const string& s);    

int main()
{
    f(10);
}

//------------------------------------------------------------------------------
