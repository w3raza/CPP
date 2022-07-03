
//
// To jest przyk�adowy kod z podrozdzia�u 19.5.3 �Gwarancje� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;

//------------------------------------------------------------------------------

namespace N1
{
    vector<int>* make_vec()    // Tworzy pe�ny wektor.
    {
        vector<int>* p = new vector<int>;    // Alokacja w pami�ci wolnej.
        // � Nape�nia wektor danymi. Tu mo�e zosta� zg�oszony wyj�tek.
        return p;
    }
}

//------------------------------------------------------------------------------

namespace N2
{
    vector<int>* make_vec()    // Tworzy pe�ny wektor.
    {
        vector<int>* p = new vector<int>;    // Alokacja w pami�ci wolnej.
        try {
            // Nape�nia wektor danymi. Tu mo�e zosta� zg�oszony wyj�tek.
            return p;
        }
        catch (...) {
            delete p;    // Lokalne czyszczenie.
            throw;       // Ponowne zg�oszenie wyj�tku, aby umo�liwi� wywo�uj�cemu poradzenie sobie
                         // z tym, �e jaka� funkcja nie by�a w stanie wykona� swojego zadania.
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    vector<int>* p = N1::make_vec();
    vector<int>* q = N2::make_vec();
    delete q;
    delete p;
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
