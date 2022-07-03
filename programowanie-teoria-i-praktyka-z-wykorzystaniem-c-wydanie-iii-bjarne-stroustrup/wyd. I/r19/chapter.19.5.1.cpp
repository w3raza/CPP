
//
// To jest przyk�adowy kod z podrozdzia�u 19.5.1 �Potencjalne problemy z zarz�dzaniem zasobami� ksi��ki
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
        int* q = new int[x]; // zajmowanie pami�ci
        int* p = new int[s]; // zajmowanie pami�ci
        // ...
        if (x) p = q;        // przestawienie p na inny obiekt
        // ...
        delete[] p;          // zwalnianie pami�ci
    }
}

//------------------------------------------------------------------------------

namespace N2
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // zajmowanie pami�ci
        // ...
        if (x) return;
        // ...
        delete[] p;          // zwalnianie pami�ci
    }
}

//------------------------------------------------------------------------------

namespace N3
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // zajmowanie pami�ci
        vector<int> v;
        // ...
        if (x) p[x] = v.at(x);
        // ...
        delete[] p;          // zwalnianie pami�ci
    }
}

//------------------------------------------------------------------------------

namespace N4
{
    void suspicious(int s, int x)
    {
        int* p = new int[s]; // zajmowanie pami�ci
        vector<int> v;
        // ...
        try {
            if (x) p[x] = v.at(x);
            // ...
        } catch (...) {      // przechwytywanie wszystkich wyj�tk�w
            delete[] p;      // zwalnianie pami�ci
            throw;           // ponowne zg�oszenie wyj�tku
        }
        // ...
        delete[] p;          // zwalnianie pami�ci
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
    std::cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    std::cerr << "Ojej: nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
