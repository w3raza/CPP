
//
// To jest przyk�adowy kod z podrozdzia�u 19.5.4 �Obiekt auto_ptr� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using std::auto_ptr;
using std::vector;

//------------------------------------------------------------------------------

vector<int>* make_vec()    // Tworzy pe�ny wektor.
{
    auto_ptr< vector<int> > p(new vector<int>); // Alokacja w pami�ci wolnej.
    // Nape�nia wektor danymi. Tu mo�e zosta� zg�oszony wyj�tek.
    return p.release(); // Zwraca wska�nik przechowywany przez p.
}

//------------------------------------------------------------------------------

int main()
try
{
    auto_ptr< vector<int> > p(make_vec());
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
