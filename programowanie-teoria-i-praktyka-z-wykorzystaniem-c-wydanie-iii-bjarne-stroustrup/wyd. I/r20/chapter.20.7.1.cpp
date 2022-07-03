
//
// To jest przyk�adowy kod z podrozdzia�u 20.7.1 �Funkcje insert() i erase()� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int initializer[7] = {1,2,3,4,5,6,7};
    int* first = initializer;
    int* last  = initializer+7;

    // Dla por�wnania zrobimy dok�adnie to samo z wektorem:
    {
        vector<int> v(first, last);
        vector<int>::iterator p = v.begin(); // wektor
        ++p; ++p; ++p;                       // wskazuje czwarty element wektora
        vector<int>::iterator q = p;
        ++q;                                 // wskazuje pi�ty element wektora

        p = v.insert(p,99);                  // p wskazuje wstawiony element.
        p = v.erase(p);                      // p wskazuje element znajduj�cy si� za elementem usuni�tym.
    }
    // Dla por�wnania zrobimy dok�adnie to samo z list�:
    {
        list<int> v(first, last);
        list<int>::iterator p = v.begin();   // lista
        ++p; ++p; ++p;                       // wskazuje czwarty element listy
        list<int>::iterator q = p;
        ++q;                                 // wskazuje pi�ty element listy
    }
}

//------------------------------------------------------------------------------
