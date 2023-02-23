
//
// Przyk³adowy kod z rozdzia³u 5.9.1 "Praktyczna rada dotycz¹ca debugowania" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void infinite()
{
    int j = 0;
    int max = 10;
    vector<int> v(10, 777);
    for (int i = 0; i<=max; ++j) {  // b³¹d (a nawet dwa)
        for (int i=0; 0<max; ++i);  // Drukuje elementy wektora v.
        cout << "v[" << i << "]==" << v[i] << '\n';
    }
}

//------------------------------------------------------------------------------

int my_fct(int a, double d)
{
    int res = 0;
    cerr << "my_fct(" << a << "," << d << ")\n";
    // ... Ÿle dzia³aj¹cy kod ...
    cerr << "my_fct() zwraca " << res << '\n';
    return res;
}

//------------------------------------------------------------------------------

int my_complicated_function(int a, int b, int c)
// Argumenty musz¹ byæ dodatnie oraz a < b < c.
{
    if (!(0<a && a<b && b<c))    // ! oznacza "nie", a && oznacza "i".
        error("Nieprawid³owe argumenty funkcji mcf.");
    // ...
}

//------------------------------------------------------------------------------

int main()
try
{
    my_fct(2, 3.37);
    my_complicated_function(1, 2, 3);
    my_complicated_function(3, 2, 1);
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
