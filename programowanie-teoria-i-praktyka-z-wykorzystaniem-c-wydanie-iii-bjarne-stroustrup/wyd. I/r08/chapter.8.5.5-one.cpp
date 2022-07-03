
//
// To jest przyk�adowy kod z podrozdzia�u 8.5.5 �Przekazywanie przez referencj� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void init(vector<double>& v)      // Przekazywanie przez referencj�.
{
  for (int i = 0; i<v.size(); ++i) v[i] = i;
}

//------------------------------------------------------------------------------

void g(int x)
{
    vector<double> vd1(10);       // Ma�y wektor
    vector<double> vd2(1000000);  // Du�y wektor
    vector<double> vd3(x);        // Wektor o nieznanym rozmiarze

    init(vd1);
    init(vd2);
    init(vd3);
}

//------------------------------------------------------------------------------

int main()
{
    g(10);
}

//------------------------------------------------------------------------------
