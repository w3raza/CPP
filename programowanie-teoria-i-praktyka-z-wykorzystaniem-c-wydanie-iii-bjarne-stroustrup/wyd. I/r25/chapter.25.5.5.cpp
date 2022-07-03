
//
// To jest przyk�adowy kod z podrozdzia�u 25.5.5 �Pola bitowe� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

struct PPN { // Physical Page Number R6000
    unsigned int PFN : 22 ;    // Page Frame Number
    int : 3 ;                  // nieu�ywany
    unsigned int CCA : 3 ;     // Cache Coherency Algorithm
    bool nonreachable : 1 ;
    bool dirty : 1 ;
    bool valid : 1 ;
    bool global : 1 ;
};

//------------------------------------------------------------------------------

void part_of_VM_system(PPN * p )
{
    // ...
    if (p->dirty) { // zmiana zawarto�ci
                    // kopiowanie na dysk
        p->dirty = 0 ;
    }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    // Automatyczne wyodr�bnianie
    {
        PPN pn = {0};
        unsigned int x = pn.CCA;         // Wydobywa CCA.
    }

    // Manual extraction
    {
        unsigned int pn = 0;
        unsigned int y = (pn>>3)&0x7;    // Wydobywa CCA.
    }
}

//------------------------------------------------------------------------------
