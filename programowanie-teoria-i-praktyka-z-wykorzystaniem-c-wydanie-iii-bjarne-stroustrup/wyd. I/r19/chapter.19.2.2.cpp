
//
// To jest przyk�adowy kod z podrozdzia�u 19.2.2 �Rezerwacja pami�ci i pojemno�� kontenera� ksi��ki
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
    void reserve(int newalloc);
    int  capacity() const;
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) {}

//------------------------------------------------------------------------------

void vector::reserve(int newalloc)
{
    if (newalloc<=space) return;             // Nigdy nie zmniejszaj obszaru alokacji.
    double* p = new double[newalloc];        // Alokuje now� przestrze�.
    for (int i=0; i<sz; ++i) p[i] = elem[i]; // Kopiuje stare elementy.
    delete[ ] elem;                          // Dealokuje star� przestrze�.
    elem = p;
    space = newalloc;        
}

//------------------------------------------------------------------------------

int vector::capacity() const { return space; }

//------------------------------------------------------------------------------

int main()
{
    vector v;
    v.reserve(10);
    return v.capacity();
}

//------------------------------------------------------------------------------
