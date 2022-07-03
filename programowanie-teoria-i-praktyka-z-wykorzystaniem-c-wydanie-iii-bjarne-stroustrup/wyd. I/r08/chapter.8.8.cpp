
//
// To jest przyk³adowy kod z podrozdzia³u 8.8 „Æwiczenia” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

//------------------------------------------------------------------------------

using std::cout;

namespace X
{
    int var = 0;

    void print()
    {
        cout << var << '\n';
    }
};

//------------------------------------------------------------------------------

namespace Y
{
    int var = 0;

    void print()
    {
        cout << var << '\n';
    }
};

//------------------------------------------------------------------------------

namespace Z
{
    int var = 0;

    void print()
    {
        cout << var << '\n';
    }
};

//------------------------------------------------------------------------------

int main()
{
    X::var = 7;
    X::print();    // Drukuje var przestrzeni nazw X.
    using namespace  Y;
    var = 9;
    print();       // Drukuje var przestrzeni nazw Y.
    {    
        using Z::var;
        using Z::print;
        var = 11;
        print();   // Drukuje var przestrzeni nazw Z.
    }
    print();       // Drukuje var przestrzeni nazw Y.
    X::print();    // Drukuje var przestrzeni nazw X.
}

//------------------------------------------------------------------------------
