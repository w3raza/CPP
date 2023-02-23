
//
// To jest przyk³adowy kod z podrozdzia³u 19.5.3 „Gwarancje” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;

//------------------------------------------------------------------------------

namespace N1
{
    vector<int>* make_vec()    // Tworzy pe³ny wektor.
    {
        vector<int>* p = new vector<int>;    // Alokacja w pamiêci wolnej.
        // … Nape³nia wektor danymi. Tu mo¿e zostaæ zg³oszony wyj¹tek.
        return p;
    }
}

//------------------------------------------------------------------------------

namespace N2
{
    vector<int>* make_vec()    // Tworzy pe³ny wektor.
    {
        vector<int>* p = new vector<int>;    // Alokacja w pamiêci wolnej.
        try {
            // Nape³nia wektor danymi. Tu mo¿e zostaæ zg³oszony wyj¹tek.
            return p;
        }
        catch (...) {
            delete p;    // Lokalne czyszczenie.
            throw;       // Ponowne zg³oszenie wyj¹tku, aby umo¿liwiæ wywo³uj¹cemu poradzenie sobie
                         // z tym, ¿e jakaœ funkcja nie by³a w stanie wykonaæ swojego zadania.
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
    std::cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    std::cerr << "Ojej: nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
