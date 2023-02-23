
//
// To jest przyk�adowy kod z podrozdzia�u 25.5.4 �Manipulowanie bitami� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

void f(short val)    // Przyjmuje 16-bitow� czyli 2-bajtow� liczb� ca�kowit� typu short.
{
    unsigned char left = val&0xff;        // Pierwszy bajt z lewej (najmniej znacz�cy).
    unsigned char right = (val>>8)&0xff;  // Pierwszy bajt z prawej (najbardziej znacz�cy).
    // ...
    bool negative = val&0x800;            // bit znaku
    // ...
}

//------------------------------------------------------------------------------

// Do nadawania nazw bitom cz�sto wykorzystuje si� wyliczenia.
enum Printer_flags {
    acknowledge=1,
    paper_empty=1<<1,
    busy=1<<2,
    out_of_black=1<<3,
    out_of_color=1<<4, 
    // ...
};

//------------------------------------------------------------------------------

int main()
{
    unsigned char x = out_of_color | out_of_black; // x otrzymuje warto�� 24 (16+8)
    x |= paper_empty;                              // x otrzymuje warto�� 26 (24+2)

    if (x& out_of_color) {                         // Czy bit out_of_color jest ustawiony? Tak.
        // ... 
    }

    // Nadal mo�na u�ywa� operatora & do maskowania

    unsigned char y = x &(out_of_color | out_of_black); // x otrzymuje warto�� 12

    Printer_flags z = Printer_flags(out_of_color | out_of_black); // Rzutowanie jest konieczne.
}

//------------------------------------------------------------------------------
