
//
// To jest przyk�adowy kod z podrozdzia�u 9.2 �Klasy i sk�adowe klas� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class X {
public:
    int m;              // Zmienna sk�adowa.
    int mf(int v) { int old = m; m=v; return old; } // Funkcja sk�adowa.
};

//------------------------------------------------------------------------------

int main()
{
    X var;              // var jest zmienn� typu X.
    var.m = 7;          // Przypisanie do sk�adowe m obiektu var.
    int x = var.mf(9);  // Wywo�anie funkcji sk�adowej mf() obiektu var.
    return x;
}

//------------------------------------------------------------------------------
