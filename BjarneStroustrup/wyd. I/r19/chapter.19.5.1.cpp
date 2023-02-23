
//
// To jest przyk³adowy kod z podrozdzia³u 19.5.1 „Potencjalne problemy z zarz¹dzaniem zasobami” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;

//------------------------------------------------------------------------------

namespace N1
{
    void suspicious(int s, int x)
    {
        int* q = new int[x]; // zajmowanie pamiêci
        int* p = new int[s]; // zajmowanie pamiêci
        // ...
        if (x) p = q;        // przestawienie p na inny obiekt
        // ...
        delete[] p;          // zwalnianie pamiêci
    }
}

//------------------------------------------------------------------------------

namespace N2
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // zajmowanie pamiêci
        // ...
        if (x) return;
        // ...
        delete[] p;          // zwalnianie pamiêci
    }
}

//------------------------------------------------------------------------------

namespace N3
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // zajmowanie pamiêci
        vector<int> v;
        // ...
        if (x) p[x] = v.at(x);
        // ...
        delete[] p;          // zwalnianie pamiêci
    }
}

//------------------------------------------------------------------------------

namespace N4
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // zajmowanie pamiêci
        vector<int> v;
        // ...
        try {
            if (x) p[x] = v.at(x);
            // ...
        } catch (...) {      // przechwytywanie wszystkich wyj¹tków
            delete[] p;      // zwalnianie pamiêci
            throw;           // ponowne zg³oszenie wyj¹tku
        }
        // ...
        delete[] p;          // zwalnianie pamiêci
    }
}

//------------------------------------------------------------------------------

namespace N5
{
    void suspicious(vector<int>& v, int s)
    {
        int* p = new int[s];
        vector<int>v1;
        // ...
        int* q = new int[s];
        vector<double> v2;
        // ...
        delete[] p;
        delete[] q;
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int> v(100);

    N1::suspicious(4,4);
    N2::suspicious(4,4);
    N3::suspicious(4,4);
    N4::suspicious(4,4);
    N5::suspicious(v,4);
}
catch (std::exception& e) {
    std::cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    std::cerr << "Ojej: nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
