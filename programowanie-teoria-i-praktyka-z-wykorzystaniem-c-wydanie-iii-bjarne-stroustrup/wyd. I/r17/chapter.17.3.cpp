
//
// To jest przyk�adowy kod z podrozdzia�u 17.3 "Pami��, adresy i wska�niki" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int  var = 17;
    int* ptr = &var;    // Zmienna ptr przechowuje adres obiektu o nazwie var.

    char  ch = 'c';
    char* pc = &ch;     // wska�nik do char

    int  ii = 17;
    int* pi =&ii;       // wska�nik do int

    cout << "pc==" << pc
        << "; contents of pc==" << *pc << "\n"; 
    cout << "pi==" << pi
        << "; contents of pi==" << *pi << "\n";

    *pc ='x';    // Dobrze: mo�na przypisa� znak 'x' do typu char wskazywanego przez pc.
    *pi = 27;    // Dobrze: wska�nik int* wskazuje liczb� typu int, a wi�c *pi jest typu int.
    *pi = *pc;   // Dobrze: mo�na przypisa� typ char (pc) do typu int (pi).


    //int i = pi;  // B��d: nie mo�na przypisa� typu int* do typu int.
    //pi = 7;      // B��d: nie mo�na przypisa� typu int do typu int*.

    //pc = pi;     // B��d: nie mo�na przypisa� typu int* do typu char*.
    //pi = pc;     // B��d: nie mo�na przypisa� typu char* do typu int*.

    {
        char ch1 = 'a';
        char ch2 = 'b';
        char ch3 = 'c';
        char ch4 = 'd';
        //int* pi = &ch3; // Wskazuje ch3 � fragment pami�ci o rozmiarze obiektu typu char.
                        // B��d: nie mo�na przypisa� typu char* do typu int*,
                        // ale udajemy, �e mo�na.
        *pi = 12345;    // Zapis we fragmencie pami�ci o rozmiarze obiektu typu int.
        *pi = 67890;
    }
}

//------------------------------------------------------------------------------
