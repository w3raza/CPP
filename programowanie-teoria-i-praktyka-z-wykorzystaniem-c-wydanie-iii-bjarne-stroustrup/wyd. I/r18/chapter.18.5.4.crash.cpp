
//
// To jest przyk³adowy kod z podrozdzia³u 18.5.4 „Problemy ze wskaŸnikami” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class vector {
    int sz;
    double* elem;
    void copy(const vector& arg);                 // Kopiuje elementy z arg do *elem.
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    vector(const vector&) ;                       // Konstruktor kopiuj¹cy — definiuje kopiowanie.
    ~vector() { delete[] elem; }                  // destruktor

    int size() const { return sz; }               // aktualny rozmiar

    double get(int n) { return elem[n]; }         // dostêp: odczyt
    void set(int n, double v) { elem[n]=v; }      // dostêp: zapis
    double& operator[](int n) { return elem[n]; } // zwraca referencjê
    // ...
};

//------------------------------------------------------------------------------

void fct_that_can_receive_a_0(int* p)
{
    if (p == 0) {
        // robi coœ
    }
    else {
        // u¿ywanie p
        *p =7;
    }
}

//------------------------------------------------------------------------------

int* fct_that_can_return_a_0()
{
    return 0;
}

//------------------------------------------------------------------------------

// Don't return a pointer to a local variable:
int* f()
{
    int x = 7;
    // ...
    return &x;
}

//------------------------------------------------------------------------------

vector& ff()
{
    vector x(7);
    // ...
    return x;
}    // Usuniêcie wektora x.

int main()
{
    // Nie uzyskuj dostêpu przez zerowy wskaŸnik.
    {
        int* p = 0;
        *p = 7;      // Au!
    }

    int* p = fct_that_can_return_a_0();
    if (p == 0) { 
        // jakieœ instrukcje
    }
    else {
        // u¿ycie p
        *p = 7;
    }

    // Inicjuj swoje wskaŸniki.
    {
        int* p;
        *p = 9;      // OAu!
    }

    // Nie uzyskuj dostêpu do nieistniej¹cych elementów tablic.
    {
        int a[10];
        int* p = &a[10];
        *p = 11;     // Au!
        a[10] = 12;  // Au!
    }

    // Nie uzyskuj dostêpu poprzez usuniêty wskaŸnik.
    {
        int* p = new int(7);
        // ...
        delete p;
        // ...
        *p = 13;     // Au!
    }

    // Nie zwracaj wskaŸnika do lokalnej zmiennej.
    {
        int* p = f();
        // ...
        *p = 15;     // Au!

    }

    // Rozwa¿ logicznie ekwiwalentny kod:
    {
        vector& p = ff();
        // ...
        p[4] = 15;     // Au!
    }
}

//------------------------------------------------------------------------------
