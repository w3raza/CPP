
//
// To jest przyk�adowy kod z podrozdzia�u 19.2.1 �Reprezentacja� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class vector {
    int sz;       // liczba element�w
    double* elem; // adres pierwszego elementu
    int space;    // liczba element�w plus �wolna przestrze�
                  // dla nowych element�w (�bie��cy rozmiar alokacji�)
public:
    vector();
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) { }

int main()
{
    vector v;
}

//------------------------------------------------------------------------------
