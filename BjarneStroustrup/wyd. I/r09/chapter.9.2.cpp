
//
// To jest przyk³adowy kod z podrozdzia³u 9.2 „Klasy i sk³adowe klas” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class X {
public:
    int m;              // Zmienna sk³adowa.
    int mf(int v) { int old = m; m=v; return old; } // Funkcja sk³adowa.
};

//------------------------------------------------------------------------------

int main()
{
    X var;              // var jest zmienn¹ typu X.
    var.m = 7;          // Przypisanie do sk³adowe m obiektu var.
    int x = var.mf(9);  // Wywo³anie funkcji sk³adowej mf() obiektu var.
    return x;
}

//------------------------------------------------------------------------------
