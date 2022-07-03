
//
// To jest przyk≥adowy kod z podrozdzia≥u 17.3 "PamiÍÊ, adresy i wskaüniki" ksiπøki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
{
    int  var = 17;
    int* ptr = &var;    // Zmienna ptr przechowuje adres obiektu o nazwie var.

    char  ch = 'c';
    char* pc = &ch;     // wskaünik do char

    int  ii = 17;
    int* pi =&ii;       // wskaünik do int

    cout << "pc==" << pc
        << "; contents of pc==" << *pc << "\n"; 
    cout << "pi==" << pi
        << "; contents of pi==" << *pi << "\n";

    *pc ='x';    // Dobrze: moøna przypisaÊ znak 'x' do typu char wskazywanego przez pc.
    *pi = 27;    // Dobrze: wskaünik int* wskazuje liczbÍ typu int, a wiÍc *pi jest typu int.
    *pi = *pc;   // Dobrze: moøna przypisaÊ typ char (pc) do typu int (pi).


    //int i = pi;  // B≥πd: nie moøna przypisaÊ typu int* do typu int.
    //pi = 7;      // B≥πd: nie moøna przypisaÊ typu int do typu int*.

    //pc = pi;     // B≥πd: nie moøna przypisaÊ typu int* do typu char*.
    //pi = pc;     // B≥πd: nie moøna przypisaÊ typu char* do typu int*.

    {
        char ch1 = 'a';
        char ch2 = 'b';
        char ch3 = 'c';
        char ch4 = 'd';
        //int* pi = &ch3; // Wskazuje ch3 ó fragment pamiÍci o rozmiarze obiektu typu char.
                        // B≥πd: nie moøna przypisaÊ typu char* do typu int*,
                        // ale udajemy, øe moøna.
        *pi = 12345;    // Zapis we fragmencie pamiÍci o rozmiarze obiektu typu int.
        *pi = 67890;
    }
}

//------------------------------------------------------------------------------
