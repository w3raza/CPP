
//
// To jest przyk³adowy kod z podrozdzia³u 19.5.4 „Obiekt auto_ptr” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using std::auto_ptr;
using std::vector;

//------------------------------------------------------------------------------

vector<int>* make_vec()    // Tworzy pe³ny wektor.
{
    auto_ptr< vector<int> > p(new vector<int>); // Alokacja w pamiêci wolnej.
    // Nape³nia wektor danymi. Tu mo¿e zostaæ zg³oszony wyj¹tek.
    return p.release(); // Zwraca wskaŸnik przechowywany przez p.
}

//------------------------------------------------------------------------------

int main()
try
{
    auto_ptr< vector<int> > p(make_vec());
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
