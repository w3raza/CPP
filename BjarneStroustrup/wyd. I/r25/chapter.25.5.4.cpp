
//
// To jest przyk³adowy kod z podrozdzia³u 25.5.4 „Manipulowanie bitami” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

void f(short val)    // Przyjmuje 16-bitow¹ czyli 2-bajtow¹ liczbê ca³kowit¹ typu short.
{
    unsigned char left = val&0xff;        // Pierwszy bajt z lewej (najmniej znacz¹cy).
    unsigned char right = (val>>8)&0xff;  // Pierwszy bajt z prawej (najbardziej znacz¹cy).
    // ...
    bool negative = val&0x800;            // bit znaku
    // ...
}

//------------------------------------------------------------------------------

// Do nadawania nazw bitom czêsto wykorzystuje siê wyliczenia.
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
    unsigned char x = out_of_color | out_of_black; // x otrzymuje wartoœæ 24 (16+8)
    x |= paper_empty;                              // x otrzymuje wartoœæ 26 (24+2)

    if (x& out_of_color) {                         // Czy bit out_of_color jest ustawiony? Tak.
        // ... 
    }

    // Nadal mo¿na u¿ywaæ operatora & do maskowania

    unsigned char y = x &(out_of_color | out_of_black); // x otrzymuje wartoœæ 12

    Printer_flags z = Printer_flags(out_of_color | out_of_black); // Rzutowanie jest konieczne.
}

//------------------------------------------------------------------------------
